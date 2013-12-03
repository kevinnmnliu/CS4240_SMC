class Type
{
public:
	virtual ~type(cPlayer&) = 0;
    virtual void Downgrade_Player(cPlayer&) = 0;
	virtual void Start_Jump(cPlayer&)= 0;

	virtual void Update_Item(cPlayer&)=0;
	virtual void Get_Item(cPlayer&);

	virtual void Set_Type(cPlayer&)=0;
	virtual void Update(cPlayer&)=0;
//done until here- 11/2
	virtual void Draw_Animation(cPlayer&)=0;
	virtual int Get_Image(cPlayer&)=0;
	virtual void Load_Image(cPlayer&)=0;


	virtual void Action_Shoot(cPlayer&);

	virtual void Ball_Add(cPlayer&)=0;

	virtual void Validate_Collision(cPlayer&) =0;
	virtual void Handle_Collision_Enemy(cPlayer&)=0;
};
class DEAD_MARYO: public Type
{
    void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }


	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
	  
    {
    	Maryo_type maryo_type = cp->maryo_type;
    	
    	if( new_mtype == maryo_type || maryo_type == MARYO_DEAD || new_mtype == MARYO_DEAD )
	{
		return;
	}

	Maryo_type maryo_type_old = maryo_type;
	bool parachute_old = cp->parachute;

	float posx_old = m_pos_x;
	float posy_old = m_pos_y;

	// Change_Size needs new state size
	maryo_type = maryo_type_old;
	cp->parachute = parachute_old;
	Load_Images();

	// correct position for bigger maryo
	if( maryo_type_old == MARYO_SMALL && ( new_mtype == MARYO_BIG || new_mtype == MARYO_FIRE || new_mtype == MARYO_ICE || new_mtype == MARYO_CAPE || new_mtype == MARYO_GHOST ) )
	{
		Change_Size( -5.0f, -12.0f );
	}
	// correct position for small maryo
	else if( ( maryo_type_old == MARYO_BIG || maryo_type_old == MARYO_FIRE || maryo_type_old == MARYO_ICE || new_mtype == MARYO_CAPE || maryo_type_old == MARYO_GHOST ) && new_mtype == MARYO_SMALL )
	{
		Change_Size( 5.0f, 12.0f );
	}

	float posx_new = m_pos_x;
	float posy_new = m_pos_y;

	// draw animation
	for( unsigned int i = 0; i < 7; i++ )
	{
		// set to current type
		if( i % 2 )
		{
			maryo_type = maryo_type_old;
			cp->parachute = parachute_old;
			Load_Images();
			
			Set_Pos( posx_old, posy_old );
		}
		// set to new type
		else
		{
			maryo_type = new_mtype;
			if( new_mtype != MARYO_CAPE )
			{
				cp->parachute = 0;
			}
			Load_Images();
			
			// always set the ghost type to draw the ghost rect until it ends
			if( i < 6 && maryo_type_old == MARYO_GHOST )
			{
				maryo_type = maryo_type_old;
			}

			Set_Pos( posx_new, posy_new );
		}

		// draw
		Draw_Game();
		pVideo->Render();

		// frame delay
		SDL_Delay( 120 );
	}

	pFramerate->Reset();

        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_state mState = cp->m_state;
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
	    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}
		if( mState == STA_STAY || mState == STA_WALK ||  mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
        return;
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}

class SMALL_MARYO: public Type
{
    void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }
	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
    {
        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_state mState = cp->m_state;
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}
		if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
	    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}
		if( mState == STA_STAY || mState == STA_WALK ||  mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
	cp->Clear_Images();

	// special maryo images state
	std::string special_state;
	// if holding item
	if( cp->active_object )
	{
		special_state = "_holding";
	}
			// standing
		Add_Image( pVideo->Get_Surface( "maryo/small/stand_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/stand_right" + special_state + ".png" ) );
		// walking
		Add_Image( pVideo->Get_Surface( "maryo/small/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/walk_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/walk_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/walk_right_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/walk_right_1" + special_state + ".png" ) );
		// running
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		// falling
		Add_Image( pVideo->Get_Surface( "maryo/small/fall_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/fall_right" + special_state + ".png" ) );
		// jumping
		Add_Image( pVideo->Get_Surface( "maryo/small/jump_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/jump_right" + special_state + ".png" ) );
		// dead
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_right.png" ) );
		// ducked
		Add_Image( pVideo->Get_Surface( "maryo/small/duck_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/duck_right.png" ) );
		// climbing
		Add_Image( pVideo->Get_Surface( "maryo/small/climb_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/climb_right.png" ) );
        cp->Set_Image_Num( cp->Get_Image() + cp->m_direction );
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}

class GHOST_MARYO: public Type
{
    void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }


	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
    {
        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_state mState = cp->m_state;
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
	    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}

		if( mState == STA_STAY || mState == STA_WALK ||  mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
	cp->Clear_Images();

	// special maryo images state
	std::string special_state;
	// if holding item
	if( cp->active_object )
	{
		special_state = "_holding";
	}
			Add_Image( pVideo->Get_Surface( "maryo/ghost/stand_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/stand_right" + special_state + ".png" ) );
		// walking
		Add_Image( pVideo->Get_Surface( "maryo/ghost/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/walk_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/walk_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/walk_right_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/walk_right_1" + special_state + ".png" ) );
		// running
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		// falling
		Add_Image( pVideo->Get_Surface( "maryo/ghost/fall_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/fall_right" + special_state + ".png" ) );
		// jumping
		Add_Image( pVideo->Get_Surface( "maryo/ghost/jump_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/fall_right" + special_state + ".png" ) );
		// dead
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_right.png" ) );
		// ducked
		Add_Image( pVideo->Get_Surface( "maryo/ghost/duck_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/duck_right.png" ) );
		// climbing
		Add_Image( pVideo->Get_Surface( "maryo/ghost/climb_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ghost/climb_right.png" ) );
		// throwing
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
        cp->Set_Image_Num( cp->Get_Image() + cp->m_direction );
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}

class CAPE_MARYO: public Type
{
     void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }


	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
    {
        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_state mState = cp->m_state;
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
	    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}
		if( mState == STA_STAY || mState == STA_WALK  )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
	cp->Clear_Images();

	// special maryo images state
	std::string special_state;
	// if holding item
	if( cp->active_object )
	{
		special_state = "_holding";
	}
			// standing
		Add_Image( pVideo->Get_Surface( "maryo/flying/left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/right" + special_state + ".png" ) );
		// walking
		Add_Image( pVideo->Get_Surface( "maryo/flying/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/walk_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/walk_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/walk_right_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/walk_right_1" + special_state + ".png" ) );
		// running
		Add_Image( pVideo->Get_Surface( "maryo/flying/run_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/run_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/run_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/run_right_2" + special_state + ".png" ) );
		// falling
		Add_Image( pVideo->Get_Surface( "maryo/flying/fall_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fall_right" + special_state + ".png" ) );
		// jumping
		Add_Image( pVideo->Get_Surface( "maryo/flying/jump_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fall_right" + special_state + ".png" ) );
		// dead
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_right.png" ) );
		// ducked
		Add_Image( pVideo->Get_Surface( "maryo/flying/duck_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/duck_right.png" ) );
		// climbing
		Add_Image( pVideo->Get_Surface( "maryo/flying/climb_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/climb_right.png" ) );
		// throwing
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		// flying
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_left_1.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_right_1.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_left_2.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_right_2.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_left_3.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_right_3.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_left_4.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/fly_right_4.png" ) );
		// slow fall/parachute
		Add_Image( pVideo->Get_Surface( "maryo/flying/slow_fall_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/flying/slow_fall_right.png" ) );
        cp->Set_Image_Num( cp->Get_Image() + cp->m_direction );
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}

class BIG_MARYO: public Type
{
    void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }


	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
    {
        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_state mState = cp->m_state;
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}

    if( mState == STA_STAY || mState == STA_WALK ||  mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
	cp->Clear_Images();

	// special maryo images state
	std::string special_state;
	// if holding item
	if( cp->active_object )
	{
		special_state = "_holding";
	}
        Add_Image( pVideo->Get_Surface( "maryo/big/stand_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/stand_right" + special_state + ".png" ) );
		// walking
		Add_Image( pVideo->Get_Surface( "maryo/big/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/walk_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/walk_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/walk_right_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/walk_right_1" + special_state + ".png" ) );
		// running
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		// falling
		Add_Image( pVideo->Get_Surface( "maryo/big/fall_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/fall_right" + special_state + ".png" ) );
		// jumping
		Add_Image( pVideo->Get_Surface( "maryo/big/jump_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/jump_right" + special_state + ".png" ) );
		// dead
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_right.png" ) );
		// ducked
		Add_Image( pVideo->Get_Surface( "maryo/big/duck_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/duck_right.png" ) );
		// climbing
		Add_Image( pVideo->Get_Surface( "maryo/big/climb_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/big/climb_right.png" ) );
		// throwing
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
        cp->Set_Image_Num( cp->Get_Image() + cp->m_direction );
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}

class FIRE_MARYO: public Type
{
    void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }
	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
    {
        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_type mState = cp->m_state;
    if( cp->throwing_counter && !cp->ducked && ( mState == STA_FALL || mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || mState == STA_JUMP ) )
	{
		int imgnum = 0;

		if( cp->throwing_counter < cp->speedfactor_fps * 0.2f )
		{
			imgnum = 2;
		}

		return cp->MARYO_IMG_THROW + imgnum;
	}
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}
	    if( mState == STA_STAY || mState == STA_WALK ||  mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
	cp->Clear_Images();

	// special maryo images state
	std::string special_state;
	// if holding item
	if( cp->active_object )
	{
		special_state = "_holding";
	}
        Add_Image( pVideo->Get_Surface( "maryo/fire/stand_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/stand_right" + special_state + ".png" ) );
		// walking
		Add_Image( pVideo->Get_Surface( "maryo/fire/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/walk_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/walk_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/walk_right_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/walk_right_1" + special_state + ".png" ) );
		// running
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		// falling
		Add_Image( pVideo->Get_Surface( "maryo/fire/fall_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/fall_right" + special_state + ".png" ) );
		// jumping
		Add_Image( pVideo->Get_Surface( "maryo/fire/jump_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/fall_right" + special_state + ".png" ) );
		// dead
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_right.png" ) );
		// ducked
		Add_Image( pVideo->Get_Surface( "maryo/fire/duck_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/duck_right.png" ) );
		// climbing
		Add_Image( pVideo->Get_Surface( "maryo/fire/climb_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/climb_right.png" ) );
		// throwing
		Add_Image( pVideo->Get_Surface( "maryo/fire/throw_left_1.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/throw_right_1.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/throw_left_2.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/fire/throw_right_2.png" ) );
        cp->Set_Image_Num( cp->Get_Image() + cp->m_direction );
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}

class ICE_MARYO: public Type
{
    void Downgrade_Player(cPlayer& cp)
    {
        return;
    }
	  void Start_Jump(cPlayer& cp)
    {
        return;
    }

	  void Update_Item(cPlayer& cp)
    {
        return;
    }
	 void Get_Item(cPlayer& cp)
    {
        return;
    }


	  void Update(cPlayer& cp)
    {
        return;
    }
	  void Draw_Animation(cPlayer& cp)
    {
        return;
    }
	  int Get_Image(cPlayer& cp)
    {
    Maryo_type mState = cp->m_state;
    if( cp->throwing_counter && !(cp->ducked) && ( mState == STA_FALL || mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || mState == STA_JUMP ) )
	{
		int imgnum = 0;

		if( cp->throwing_counter < cp->speedfactor_fps * 0.2f )
		{
			imgnum = 2;
		}

		return cp->MARYO_IMG_THROW + imgnum;
	}
	if( cp->ducked && ( mState == STA_STAY || mState == STA_WALK || mState == STA_RUN || m_state == STA_JUMP || m_state == STA_FALL ) )
	{
		return MARYO_IMG_DUCK;
	}
    if( cp->parachute && mState == STA_FALL )
	{
		return MARYO_IMG_SPECIAL_1;
	}
	    if( mState == STA_STAY || mState == STA_WALK ||  mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_WALK + imgnum;
	}
	else if( mState == STA_RUN )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_RUN + imgnum;
	}
	else if( mState == STA_FALL )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FALL + imgnum;*/
		return MARYO_IMG_FALL;
	}
	/*else if( mState == STAY )
	{
		return MARYO_IMG_STAND;
	}*/
	else if( mState == STA_JUMP )
	{
		/*unsigned int imgnum = static_cast<unsigned int>(walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_JUMP + imgnum;*/
		return MARYO_IMG_JUMP;
	}
	else if( mState == STA_FLY )
	{
		unsigned int imgnum = static_cast<unsigned int>(cp->walk_count);

		for( unsigned int i = 0; i < imgnum; i++ )
		{
			if( imgnum % 2 )
			{
				imgnum--;
			}
		}

		return MARYO_IMG_FLY + imgnum;
	}
	else if( mState == STA_CLIMB )
	{
		if( cp->walk_count > 4 )
		{
			return MARYO_IMG_CLIMB;
		}
		else
		{
			return MARYO_IMG_CLIMB + 1;
		}
	}

	return MARYO_IMG_STAND;
    }
	  void Load_Image(cPlayer& cp)
    {
	cp->Clear_Images();

	// special maryo images state
	std::string special_state;
	// if holding item
	if( cp->active_object )
	{
		special_state = "_holding";
	}
		Add_Image( pVideo->Get_Surface( "maryo/ice/stand_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/stand_right" + special_state + ".png" ) );
		// walking
		Add_Image( pVideo->Get_Surface( "maryo/ice/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/walk_right_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/walk_left_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/walk_right_2" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/walk_left_1" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/walk_right_1" + special_state + ".png" ) );
		// running
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		Add_Image( NULL );
		// falling
		Add_Image( pVideo->Get_Surface( "maryo/ice/fall_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/fall_right" + special_state + ".png" ) );
		// jumping
		Add_Image( pVideo->Get_Surface( "maryo/ice/jump_left" + special_state + ".png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/fall_right" + special_state + ".png" ) );
		// dead
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/small/dead_right.png" ) );
		// ducked
		Add_Image( pVideo->Get_Surface( "maryo/ice/duck_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/duck_right.png" ) );
		// climbing
		Add_Image( pVideo->Get_Surface( "maryo/ice/climb_left.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/climb_right.png" ) );
		// throwing
		Add_Image( pVideo->Get_Surface( "maryo/ice/throw_left_1.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/throw_right_1.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/throw_left_2.png" ) );
		Add_Image( pVideo->Get_Surface( "maryo/ice/throw_right_2.png" ) );
		/****************************************************/
        cp->Set_Image_Num( cp->Get_Image() + cp->m_direction );
    }
	  void Action_Shoot(cPlayer& cp)
    {
        return;
    }
	  void Ball_Add(cPlayer& cp)
    {
        return;
    }
	  void Validate_Collision(cPlayer& cp)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer& cp)
    {
        return;
    }
}
