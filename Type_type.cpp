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
	virtual void Get_Image(cPlayer&)=0;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
	  void Get_Image(cPlayer& cp)
    {
        return;
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
