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
