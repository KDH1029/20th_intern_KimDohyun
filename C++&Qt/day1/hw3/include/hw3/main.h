namespace dohyun
{
    class Monster
    {
    public:
        int HP, x, y;
        Monster();
        Monster(int x, int y, int HP);
        int Be_Attacked();
    };
    class Player
    {
    public:
        int HP, MP, x, y;
        Player();
        Player(int x, int y);
        void Attack(Monster &target);
        void Show_Status();
        void X_move(int move);
        void Y_move(int move);
    };

    Player::Player(void)
    {
        this->x = 0;
        this->y = 0;
        this->HP = 50;
        this->MP = 10;
    }
    Player::Player(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->HP = 50;
        this->MP = 10;
    }
    void Player::Attack(Monster &target)
    {
        if (this->x == target.x && this->y == target.y)
        {
            target.Be_Attacked();
        }
        else
        {
            std::cout << "공격실패!" << std::endl;
        }
        this->MP -= 1;
    }
    void Player::Show_Status(void)
    {
        std::cout << "HP:" << this->HP << std::endl
                  << "MP:" << this->MP << std::endl
                  << "position:" << this->x << "," << this->y << std::endl;
    }
    void Player::X_move(int move)
    {
        this->x += move;
        std::cout << "X position " << move << " moved!" << std::endl;
    }
    void Player::Y_move(int move)
    {
        this->y += move;
        std::cout << "Y position " << move << " moved!" << std::endl;
    }

    Monster::Monster()
    {
        this->x = 5;
        this->y = 4;
        this->HP = 50;
    }
    Monster::Monster(int x, int y, int HP)
    {
        this->x = x;
        this->y = y;
        this->HP = HP;
    }
    int Monster::Be_Attacked(void)
    {
        this->HP -= 10;
        std::cout << "공격 성공!" << std::endl
                  << "남은 체력:" << this->HP << std::endl;
        if (this->HP <= 0)
        {
            std::cout << "Monster Die!!" << std::endl;
            return 1;
        }
        return 0;
    }
}