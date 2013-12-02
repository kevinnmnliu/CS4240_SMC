class Type
{
public:
	virtual ~type() = 0;
	virtual void Start_Jump()= 0;
	
	virtual void Update_Item()=0;
	virutal void Get_Item();
	
	virtual void Set_Type()=0;
	virtual void Update()=0;
//done until here- 11/2
	virtual void Draw_Animation()=0;
	virtual void Get_Image()=0;
	virtual void Load_Image()=0;


	virtual void Action_Shoot();
	
	virtual void Ball_Add()=0;
	
	virtual void Validate_Collision() =0;
	virtual void Handle_Collision_Enemy()=0;
};
class Jump:public Type

{
	void Start_Jump()
	{
		// play sound
		if( next_jump_sound )
		{
			// small
			if( maryo_type == MARYO_SMALL )
			{
				if( force_jump )
				{
					pAudio->Play_Sound( "player/jump_small_power.ogg", RID_MARYO_JUMP );
				}
				else
				{
					pAudio->Play_Sound( "player/jump_small.ogg", RID_MARYO_JUMP );
				}
			}
			// ghost
			else if( maryo_type == MARYO_GHOST )
			{
				pAudio->Play_Sound( "player/jump_ghost.ogg", RID_MARYO_JUMP );
			}
			// big
			else
			{
				if( force_jump )
				{
					pAudio->Play_Sound( "player/jump_big_power.ogg", RID_MARYO_JUMP );
				}
				else
				{
					pAudio->Play_Sound( "player/jump_big.ogg", RID_MARYO_JUMP );
				}
			}
		}
		
		bool jump_key = 0;
		
		// if jump key pressed
		if( pKeyboard->keys[pPreferences->m_key_jump] || ( pPreferences->m_joy_analog_jump && pJoystick->up ) || pJoystick->Button( pPreferences->m_joy_button_jump ) )
		{
			jump_key = 1;
		}
		
		// todo : is this needed ?
		// avoid that we are set on the ground again
		Col_Move( 0.0f, -1.0f, 1, 1 );
		
		// fly
		if( maryo_type == MARYO_CAPE && !force_jump && m_state == STA_RUN && jump_key && ( ( m_direction == DIR_RIGHT && m_velx > 14 ) || ( m_direction == DIR_LEFT && m_velx < -14 ) ) )
		{
			m_vely = -next_jump_power * 0.5f;
			Set_Moving_State( STA_FLY );
		}
		// jump
		else
		{
			jump_accel_up = next_jump_accel;
			jump_vel_deaccel = deaccel;
			
			if( jump_key )
			{
				jump_power = next_jump_power * 0.59f;
			}
			else
			{
				jump_power = next_jump_power * 0.12f;
			}
			
			m_vely = -next_jump_power;
			Set_Moving_State( STA_JUMP );
		}
		
		// jump higher when running
		if( m_velx < 0.0f )
		{
			m_vely += m_velx / 9.5f;
		}
		else if( m_velx > 0.0f )
		{
			m_vely -= m_velx / 9.5f;
		}
		
		// slow down if running
		m_velx = m_velx * 0.9f;
		
		// jump with velx if ducking but only into the opposite start duck direction to get out of a hole
		if( ducked )
		{
			if( m_direction == DIR_RIGHT && duck_direction != m_direction )
			{
				if( m_velx < 5.0f )
				{
					m_velx += 2.0f;
				}
			}
			else if( m_direction == DIR_LEFT && duck_direction != m_direction )
			{
				if( m_velx > -5.0f )
				{
					m_velx -= 2.0f;
				}
			}
		}
		
		// reset variables
		UpKeytime = 0.0f;
		force_jump = 0;
		next_jump_sound = 1;
		next_jump_power = 17.0f;
		next_jump_accel = 4.0f;
	}
	
	}
}
class Item:public Type 
{
	void Get_Item()
	{
	Maryo_type current_maryo_type;
	bool use_temp_power;
	
	// use original type
	if( maryo_type == MARYO_GHOST )
	{
		current_maryo_type = maryo_type_temp_power;
		use_temp_power = 1;
	}
	// already using original type
	else
	{
		current_maryo_type = maryo_type;
		use_temp_power = 0;
	}
	
	// Default Mushroom
	if( item_type == TYPE_MUSHROOM_DEFAULT ) 
	{
		if( ( current_maryo_type == MARYO_SMALL || force ) && Change_Size( -5, -12, 1 ) ) 
		{
			// change to big
			if( current_maryo_type == MARYO_SMALL )
			{
				// set type
				Set_Type( MARYO_BIG, 1, 1, use_temp_power );
			}
			// move item to itembox
			else if( current_maryo_type == MARYO_BIG )
			{
				// item to itembox
				pHud_Itembox->Set_Item( TYPE_MUSHROOM_DEFAULT );
			}
			// change to big
			else if( current_maryo_type == MARYO_FIRE )
			{
				// set type
				Set_Type( MARYO_BIG, 0, 1, use_temp_power );
				// old item to itembox
				pHud_Itembox->Set_Item( TYPE_FIREPLANT );
			}
		}
		// move item to itembox
		else
		{
			pHud_Itembox->Set_Item( TYPE_MUSHROOM_DEFAULT );
		}
	}
	// Fireplant
	else if( item_type == TYPE_FIREPLANT ) 
	{
		if( ( ( current_maryo_type == MARYO_SMALL || force ) && Change_Size( -5, -12, 1 ) ) || 
		   ( current_maryo_type == MARYO_BIG || current_maryo_type == MARYO_ICE || force ) )
		{
			// move item to itembox
			if( current_maryo_type == MARYO_FIRE ) 
			{
				// move item to itembox
				pHud_Itembox->Set_Item( TYPE_FIREPLANT );
			}
			// change to fire
			else
			{
				// set type
				Set_Type( MARYO_FIRE, 1, 1, use_temp_power );
			}
		}
		// fire explosion
		else if( current_maryo_type == MARYO_FIRE && pHud_Itembox->m_item_id == TYPE_FIREPLANT )
		{
			unsigned int ball_amount = 10;
			
			// if star add another ball
			if( invincible_star )
			{
				ball_amount = 20;
			}
			
			Ball_Add( FIREBALL_EXPLOSION, 180, ball_amount );
			pHud_Points->Add_Points( 1000, m_pos_x + ( m_col_rect.m_w / 2 ), m_pos_y + 2 );	
		}
		// move item to itembox
		else
		{
			pHud_Itembox->Set_Item( TYPE_FIREPLANT );
		}
	}
	// Blue Mushroom
	else if( item_type == TYPE_MUSHROOM_BLUE ) 
	{
		if( ( ( current_maryo_type == MARYO_SMALL || force ) && Change_Size( -5, -20, 1 ) ) || 
		   ( ( current_maryo_type == MARYO_BIG || current_maryo_type == MARYO_FIRE || force ) ) )
		{
			// move item to itembox
			if( current_maryo_type == MARYO_ICE ) 
			{
				// move item to itembox
				pHud_Itembox->Set_Item( TYPE_MUSHROOM_BLUE );
			}
			// change to ice
			else
			{
				// set type
				Set_Type( MARYO_ICE, 1, 1, use_temp_power );
			}
		}
		// ice explosion
		else if( current_maryo_type == MARYO_ICE && pHud_Itembox->m_item_id == TYPE_MUSHROOM_BLUE )
		{
			unsigned int ball_amount = 10;
			
			// if star add another ball
			if( invincible_star )
			{
				ball_amount = 20;
			}
			
			Ball_Add( ICEBALL_EXPLOSION, 180, ball_amount );
			pHud_Points->Add_Points( 1000, m_pos_x + ( m_col_rect.m_w / 2 ), m_pos_y + 2 );	
		}
		// move item to itembox
		else
		{
			pHud_Itembox->Set_Item( TYPE_MUSHROOM_BLUE );
		}
	}
	// Ghost Mushroom
	else if( item_type == TYPE_MUSHROOM_GHOST ) 
	{
		if( ( ( maryo_type == MARYO_SMALL || force ) && Change_Size( -5, -20, 1 ) ) || 
		   maryo_type != MARYO_SMALL )
		{
			// set back ghost time
			if( maryo_type == MARYO_GHOST )
			{
				ghost_time = speedfactor_fps * 10;
				ghost_time_mod = 0;
			}
			// change to ghost
			else
			{
				// set type
				Set_Type( MARYO_GHOST, 1, 1 );
			}
		}
		// move item to itembox
		else
		{
			pHud_Itembox->Set_Item( TYPE_MUSHROOM_GHOST );
		}
	}
	// Mushroom 1-UP
	else if( item_type == TYPE_MUSHROOM_LIVE_1 ) 
	{
		pAudio->Play_Sound( "item/live_up.ogg", RID_1UP_MUSHROOM );
		pHud_Lives->Add_Lives( 1 );
	}
	// Mushroom Poison
	else if( item_type == TYPE_MUSHROOM_POISON ) 
	{
		DownGrade_Player();
	}
	// Moon
	else if( item_type == TYPE_MOON ) 
	{
		pAudio->Play_Sound( "item/moon.ogg", RID_MOON );
		pHud_Lives->Add_Lives( 3 );
	}
	// Jumping Star
	else if( item_type == TYPE_JSTAR ) 
	{
		// todo : check if music is already playing
		pAudio->Play_Music( "game/star.ogg", 0, 1, 500 );
		pAudio->Play_Music( pActive_Level->m_musicfile, -1, 0 );
		pHud_Points->Add_Points( 1000, m_pos_x + ( m_col_rect.m_w / 2 ), m_pos_y + 2 );
		invincible = speedfactor_fps * 16.0f;
		invincible_star = speedfactor_fps * 15.0f;
	}
	// Turtle Shell
	else if( item_type == TYPE_TURTLE ) 
	{
		pAudio->Play_Sound( "player/pickup_item.wav" );
		
		active_object = base;
		active_object->m_massive_type = MASS_PASSIVE;
		active_object->m_state = STA_OBJ_LINKED;
		active_object->Update_Valid_Update();
		active_object->Reset_On_Ground();
		active_object->m_velx = 0;
		active_object->m_vely = 0;
		
		
		cTurtle *turtle = static_cast<cTurtle *>(active_object);
		// clear the standing counter
		turtle->m_counter = 0.0f;
		// clear player counter
		turtle->m_player_counter = 0.0f;
		turtle->Set_Image_Num( 5 );
		
		// load holding images
		Load_Images();
	}
		
	void Update_Item()
		{
			// if active object item is available
			if( active_object )
			{
				// collision with something or activated
				if( active_object->m_type == TYPE_TURTLE && static_cast<cTurtle *>(active_object)->m_dead )
				{
					Release_Item( 0 );
					return;
				}
				
				// update the item position
				float item_pos_x = 0.0f;
				float item_pos_y = 0.0f;
				
				if( maryo_type == MARYO_SMALL )
				{
					if( m_direction == DIR_LEFT )
					{
						item_pos_x = (m_rect.m_w * 0.20f) - active_object->m_col_rect.m_w;
					}
					else
					{
						item_pos_x = m_rect.m_w * 0.64f;
					}
					
					item_pos_y = m_rect.m_h * 0.14f;
				}
				// big
				else
				{
					if( m_direction == DIR_LEFT )
					{
						item_pos_x = (m_rect.m_w * 0.21f) - active_object->m_col_rect.m_w;
					}
					else
					{
						item_pos_x = m_rect.m_w * 0.66f;
					}
					
					item_pos_y = m_rect.m_h * 0.18f;
				}
				
				active_object->Set_Pos( m_pos_x + item_pos_x, m_pos_y + item_pos_y );
				
				return;
			}
			
			// invalid state
			if( m_state == STA_FLY || ducked || m_state == STA_CLIMB )
			{
				return;
			}
			
			// if control is pressed search for items in front of the player
			if( pKeyboard->keys[pPreferences->m_key_action] || pJoystick->Button( pPreferences->m_joy_button_action ) )
			{
				// next position velocity with extra size
				float check_x = ( m_velx > 0.0f ) ? ( m_velx + 5.0f ) : ( m_velx - 5.0f );
				
				// if wrong direction return
				if( ( m_direction == DIR_LEFT && check_x >= 0.0f ) || ( m_direction == DIR_RIGHT && check_x <= 0.0f ) )
				{
					return;
				}
				
				// check the next player position for objects
				cObjectCollisionType *col_list = Collision_Check_Relative( ( m_direction == DIR_LEFT ) ? (check_x) : (m_col_rect.m_w), 0, ( m_direction == DIR_LEFT ) ? (-check_x) : (check_x) );
				
				// possible objects
				for( cObjectCollision_List::iterator itr = col_list->objects.begin(), itr_end = col_list->objects.end(); itr != itr_end; ++itr )
				{
					cObjectCollision *col = (*itr);
					
					// enemy item
					if( col->m_array == ARRAY_ENEMY )
					{
						if( col->obj->m_type == TYPE_TURTLE )
						{
							cEnemy *enemy = static_cast<cEnemy *>(col->obj);
							
							if( enemy->m_state == STA_STAY )
							{
								Get_Item( TYPE_TURTLE, 0, enemy );
								break;
							}
						}
					}
					// other items here...
				}
				
				delete col_list;
			}			
	
}
	
	}

Class Types: public Types
	
{
	void Set_Type()
	{
	if( item_type == TYPE_PLAYER )
	{
		Set_Type( MARYO_SMALL, animation, sound, temp_power );
	}
	else if( item_type == TYPE_MUSHROOM_DEFAULT )
	{
		Set_Type( MARYO_BIG, animation, sound, temp_power );
	}
	else if( item_type == TYPE_MUSHROOM_BLUE )
	{
		Set_Type( MARYO_ICE, animation, sound, temp_power );
	}
	else if( item_type == TYPE_MUSHROOM_GHOST )
	{
		Set_Type( MARYO_GHOST, animation, sound, temp_power );
	}
	else if( item_type == TYPE_FIREPLANT )
	{
		Set_Type( MARYO_FIRE, animation, sound, temp_power );
	}
	if( maryo_type == new_type )
	{
		return;
	}
	
	// play sound
	if( sound )
	{
		if( new_type == MARYO_BIG )
		{
			pAudio->Play_Sound( "item/mushroom.ogg", RID_MUSHROOM );
		}
		else if( new_type == MARYO_FIRE )
		{
			pAudio->Play_Sound( "item/fireplant.ogg", RID_FIREPLANT );
		}
		else if( new_type == MARYO_ICE )
		{
			pAudio->Play_Sound( "item/mushroom_blue.wav", RID_MUSHROOM_BLUE );
		}
		else if( new_type == MARYO_CAPE )
		{
			pAudio->Play_Sound( "item/feather.ogg", RID_FEATHER );
		}
		else if( new_type == MARYO_GHOST )
		{
			pAudio->Play_Sound( "item/mushroom_ghost.ogg", RID_MUSHROOM_GHOST );
		}
	}
	
	if( !temp_power )
	{
		// was flying
		if( maryo_type == MARYO_CAPE )
		{
			Stop_Flying( 0 );
		}
	}
	
	// remember old type
	Maryo_type old_type = maryo_type;
	
	// draw animation and set new type
	if( animation )
	{
		Draw_Animation( new_type );
		
		if( temp_power )
		{
			maryo_type = old_type;
			maryo_type_temp_power = new_type;
			// Draw_Animation ends with the new type images
			Load_Images();
		}
		
	}
	// only set type
	else
	{
		if( temp_power )
		{
			maryo_type_temp_power = new_type;
		}
		else
		{
			maryo_type = new_type;
			Load_Images();
		}
	}
	
	// nothing more needed for setting the temp power
	if( temp_power )
	{
		return;
	}
	
	// to ghost
	if( maryo_type == MARYO_GHOST )
	{
		ghost_time = speedfactor_fps * 10;
		maryo_type_temp_power = old_type;
	}
	// was ghost
	else if( old_type == MARYO_GHOST )
	{
		ghost_time = 0;
		ghost_time_mod = 0;
		maryo_type_temp_power = MARYO_DEAD;
		
		// check for ghost ground
		if( m_ground_object )
		{
			cBaseBox *box = dynamic_cast<cBaseBox *>( m_ground_object );
			
			if( box )
			{
				// ghost box
				if( box->box_invisible == BOX_GHOST )
				{
					Reset_On_Ground();
				}
			}
		}
	}
	
	// check if on ground as the size could also change
	Check_on_Ground();
}
}
	Class Image:public Type
{
		
	
	
