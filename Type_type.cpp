class Type
{
public:
	virtual ~type(cPlayer&) = 0;
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
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	 void Get_Item(cPlayer&)
    {
        return;
    }

	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}

class SMALL_MARYO: public Type
{
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	void Get_Item(cPlayer&)
    {
        return;
    }
	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}

class GHOST_MARYO: public Type
{
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	  void Get_Item(cPlayer&)
    {
        return;
    }

	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}

class CAPE_MARYO: public Type
{
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	void Get_Item(cPlayer&)
    {
        return;
    }
	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}

class BIG_MARYO: public Type
{
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	void Get_Item(cPlayer&)
    {
        return;
    }
	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}

class FIRE_MARYO: public Type
{
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	void Get_Item(cPlayer&)
    {
        return;
    }
	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}

class ICE_MARYO: public Type
{
	  void Start_Jump(cPlayer&)
    {
        return;
    }
	  void Update_Item(cPlayer&)
    {
        return;
    }
	void Get_Item(cPlayer&)
    {
        return;
    }
	  void Set_Type(cPlayer&)
    {
        return;
    }
	  void Update(cPlayer&)
    {
        return;
    }
	  void Draw_Animation(cPlayer&)
    {
        return;
    }
	  void Get_Image(cPlayer&)
    {
        return;
    }
	  void Load_Image(cPlayer&)
    {
        return;
    }
	  void Action_Shoot(cPlayer&)
    {
        return;
    }
	  void Ball_Add(cPlayer&)
    {
        return;
    }
	  void Validate_Collision(cPlayer&)
    {
        return;
    }
	  void Handle_Collision_Enemy(cPlayer&)
    {
        return;
    }
}
