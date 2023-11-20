#include"Manage.cpp"
#include"chess1.cpp"
class GameModePvP{
    public:
        GameModePvP(){};

        bool turn;

        ManagePlayer Player1;
        ManageAI Player2;

        stack<Undo> U;
        Location Pdie;

        void begin()
    {
        int board[8][8] =
            {50, 10, 0, 0, 0, 0, -10, -50,
             30, 10, 0, 0, 0, 0, -10, -30,
             35, 10, 0, 0, 0, 0, -10, -35,
             90, 10, 0, 0, 0, 0, -10, -90,
             1000, 10, 0, 0, 0, 0, -10, -1000,
             35, 10, 0, 0, 0, 0, -10, -35,
             30, 10, 0, 0, 0, 0, -10, -30,
             50, 10, 0, 0, 0, 0, -10, -50};
        ;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Board[i][j] = board[i][j];
            }
        }
        
        Player1.begin();
        Player2.begin();
        

        Pdie.x=-100;
        Pdie.y=-100;
        
    }
    void banco()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (Board[j][i] == 10)
                    printf("%2s", "P");
                else if (Board[j][i] == 50)
                    printf("%2s", "R");
                else if (Board[j][i] == 30)
                    printf("%2s", "H");
                else if (Board[j][i] == 35)
                    printf("%2s", "B");
                else if (Board[j][i] == 90)
                    printf("%2s", "Q");
                else if (Board[j][i] == 1000)
                    printf("%2s", "K");
                else if (Board[j][i] == -10)
                    printf("%2s", "p");
                else if (Board[j][i] == -50)
                    printf("%2s", "r");
                else if (Board[j][i] == -30)
                    printf("%2s", "h");
                else if (Board[j][i] == -35)
                    printf("%2s", "b");
                else if (Board[j][i] == -90)
                    printf("%2s", "q");
                else if (Board[j][i] == -1000)
                    printf("%2s", "k");
                else
                    printf("%2s", "");
            }
            cout << endl;
        }
    }
    vector<Location> ValidMove(int i, int Board[][8], Pos PosA[])
    {
        // cout<<".."<<PosA[i].x<<PosA[i].y<<endl;
        vector<Location> arr;
        Location new1;
        if (PosA[i].value == -1)
            return arr;
        else if (abs(PosA[i].value) == 10)
        {
            int k = -1 * PosA[i].value / abs(PosA[i].value);
            if ((Board[PosA[i].x][PosA[i].y - k] == 0) && (PosA[i].y - k >= 0) && (PosA[i].y - k < 8))
            {
                new1.x = PosA[i].x;
                new1.y = PosA[i].y - k;
                arr.push_back(new1);
            };
            if ((PosA[i].y == 1 || PosA[i].y == 6) && (Board[PosA[i].x][PosA[i].y - 2 * k] == 0) && (Board[PosA[i].x][PosA[i].y - k] == 0) && (PosA[i].y - 2 * k >= 0) && (PosA[i].y - 2 * k < 8))
            {
                new1.x = PosA[i].x;
                new1.y = PosA[i].y - 2 * k;
                arr.push_back(new1);
            };
            if ((PosA[i].value * Board[PosA[i].x + 1][PosA[i].y - k] < 0) && (PosA[i].y - k >= 0) && (PosA[i].y - k < 8) && (PosA[i].x + 1 < 8))
            {
                new1.x = PosA[i].x + 1;
                new1.y = PosA[i].y - k;
                arr.push_back(new1);
            };
            if ((PosA[i].value * Board[PosA[i].x - 1][PosA[i].y - k] < 0) && (PosA[i].y - k >= 0) && (PosA[i].y - k < 8) && (PosA[i].x - 1 >= 0))
            {
                new1.x = PosA[i].x - 1;
                new1.y = PosA[i].y - k;
                arr.push_back(new1);
            };

            // phong hau 
            return arr;
        }
        else if (abs(PosA[i].value) == 30)
        { // 1 7
            int k = PosA[i].value / abs(PosA[i].value);
            if ((Board[PosA[i].x + 2][PosA[i].y + 1] == 0 || k * Board[PosA[i].x + 2][PosA[i].y + 1] < 0) && (PosA[i].x + 2 < 8) && (PosA[i].y + 1 < 8))
            {
                new1.x = PosA[i].x + 2;
                new1.y = PosA[i].y + 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x + 1][PosA[i].y + 2] == 0 || k * Board[PosA[i].x + 1][PosA[i].y + 2] < 0) && (PosA[i].x + 1 < 8) && (PosA[i].y + 2 < 8))
            {
                new1.x = PosA[i].x + 1;
                new1.y = PosA[i].y + 2;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 1][PosA[i].y - 2] == 0 || k * Board[PosA[i].x - 1][PosA[i].y - 2] < 0) && (PosA[i].x - 1 >= 0) && (PosA[i].y - 2 >= 0))
            {
                new1.x = PosA[i].x - 1;
                new1.y = PosA[i].y - 2;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 2][PosA[i].y - 1] == 0 || k * Board[PosA[i].x - 2][PosA[i].y - 1] < 0) && (PosA[i].x - 2 >= 0) && (PosA[i].y - 1 >= 0))
            {
                new1.x = PosA[i].x - 2;
                new1.y = PosA[i].y - 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x + 1][PosA[i].y - 2] == 0 || k * Board[PosA[i].x + 1][PosA[i].y - 2] < 0) && (PosA[i].x + 1 < 8) && (PosA[i].y - 2 >= 0))
            {
                new1.x = PosA[i].x + 1;
                new1.y = PosA[i].y - 2;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 1][PosA[i].y + 2] == 0 || k * Board[PosA[i].x - 1][PosA[i].y + 2] < 0) && (PosA[i].x - 1 >= 0) && (PosA[i].y + 2 < 8))
            {
                new1.x = PosA[i].x - 1;
                new1.y = PosA[i].y + 2;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 2][PosA[i].y + 1] == 0 || k * Board[PosA[i].x - 2][PosA[i].y + 1] < 0) && (PosA[i].x - 2 >= 0) && (PosA[i].y + 1 < 8))
            {
                new1.x = PosA[i].x - 2;
                new1.y = PosA[i].y + 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x + 2][PosA[i].y - 1] == 0 || k * Board[PosA[i].x + 2][PosA[i].y - 1] < 0) && (PosA[i].x + 2 < 8) && (PosA[i].y - 1 >= 0))
            {
                new1.x = PosA[i].x + 2;
                new1.y = PosA[i].y - 1;
                arr.push_back(new1);
            };
            return arr;
        }
        else if (abs(PosA[i].value) == 35)
        {
            int k = PosA[i].value / abs(PosA[i].value);
            for (int i1 = PosA[i].x + 1, j = PosA[i].y + 1; (i1 < 8 && j < 8); i1++, j++)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x + 1, j = PosA[i].y - 1; (i1 < 8 && j >= 0); i1++, j--)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x - 1, j = PosA[i].y - 1; (i1 >= 0 && j >= 0); i1--, j--)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x - 1, j = PosA[i].y + 1; (i1 >= 0 && j < 8); i1--, j++)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            return arr;
        }
        else if (abs(PosA[i].value) == 50)
        {
            int k = PosA[i].value / abs(PosA[i].value);
            for (int i1 = PosA[i].x + 1; i1 < 8; i1++)
            {
                if (Board[i1][PosA[i].y] != 0)
                {
                    if (Board[i1][PosA[i].y] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = PosA[i].y;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = PosA[i].y;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x - 1; i1 >= 0; i1--)
            {
                if (Board[i1][PosA[i].y] != 0)
                {
                    if (Board[i1][PosA[i].y] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = PosA[i].y;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = PosA[i].y;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].y + 1; i1 < 8; i1++)
            {
                if (Board[PosA[i].x][i1] != 0)
                {
                    if (Board[PosA[i].x][i1] * k < 0)
                    {
                        new1.x = PosA[i].x;
                        new1.y = i1;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = PosA[i].x;
                new1.y = i1;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].y - 1; i1 >= 0; i1--)
            {
                if (Board[PosA[i].x][i1] != 0)
                {
                    if (Board[PosA[i].x][i1] * k < 0)
                    {
                        new1.x = PosA[i].x;
                        new1.y = i1;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = PosA[i].x;
                new1.y = i1;
                arr.push_back(new1);
            }
            return arr;
        }
        else if (abs(PosA[i].value) == 90)
        {
            int k = PosA[i].value / abs(PosA[i].value);
            for (int i1 = PosA[i].x + 1, j = PosA[i].y + 1; (i1 < 8 && j < 8); i1++, j++)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x + 1, j = PosA[i].y - 1; (i1 < 8 && j >= 0); i1++, j--)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x - 1, j = PosA[i].y - 1; (i1 >= 0 && j >= 0); i1--, j--)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x - 1, j = PosA[i].y + 1; (i1 >= 0 && j < 8); i1--, j++)
            {

                if (Board[i1][j] != 0)
                {
                    if (Board[i1][j] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = j;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = j;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x + 1; i1 < 8; i1++)
            {
                if (Board[i1][PosA[i].y] != 0)
                {
                    if (Board[i1][PosA[i].y] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = PosA[i].y;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = PosA[i].y;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].x - 1; i1 >= 0; i1--)
            {
                if (Board[i1][PosA[i].y] != 0)
                {
                    if (Board[i1][PosA[i].y] * k < 0)
                    {
                        new1.x = i1;
                        new1.y = PosA[i].y;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = i1;
                new1.y = PosA[i].y;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].y + 1; i1 < 8; i1++)
            {
                if (Board[PosA[i].x][i1] != 0)
                {
                    if (Board[PosA[i].x][i1] * k < 0)
                    {
                        new1.x = PosA[i].x;
                        new1.y = i1;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = PosA[i].x;
                new1.y = i1;
                arr.push_back(new1);
            }
            for (int i1 = PosA[i].y - 1; i1 >= 0; i1--)
            {
                if (Board[PosA[i].x][i1] != 0)
                {
                    if (Board[PosA[i].x][i1] * k < 0)
                    {
                        new1.x = PosA[i].x;
                        new1.y = i1;
                        arr.push_back(new1);
                    };
                    break;
                }
                new1.x = PosA[i].x;
                new1.y = i1;
                arr.push_back(new1);
            }
            return arr;
        }
        else if (abs(PosA[i].value) == 1000)
        {
            int k = PosA[i].value / abs(PosA[i].value);
            if ((Board[PosA[i].x + 1][PosA[i].y] * k <= 0) && (PosA[i].x + 1 < 8))
            {
                new1.x = PosA[i].x + 1;
                new1.y = PosA[i].y;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x + 1][PosA[i].y + 1] * k <= 0) && (PosA[i].x + 1 < 8) && (PosA[i].y + 1 < 8))
            {
                new1.x = PosA[i].x + 1;
                new1.y = PosA[i].y + 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x + 1][PosA[i].y - 1] * k <= 0) && (PosA[i].x + 1 < 8) && (PosA[i].y - 1 >= 0))
            {
                new1.x = PosA[i].x + 1;
                new1.y = PosA[i].y - 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 1][PosA[i].y] * k <= 0) && (PosA[i].x - 1 >= 0))
            {
                new1.x = PosA[i].x - 1;
                new1.y = PosA[i].y;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 1][PosA[i].y + 1] * k <= 0) && (PosA[i].x - 1 >= 0) && (PosA[i].y + 1 < 8))
            {
                new1.x = PosA[i].x - 1;
                new1.y = PosA[i].y + 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x - 1][PosA[i].y - 1] * k <= 0) && (PosA[i].x - 1 >= 0) && (PosA[i].y - 1 >= 0))
            {
                new1.x = PosA[i].x - 1;
                new1.y = PosA[i].y - 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x][PosA[i].y + 1] * k <= 0) && (PosA[i].y + 1 < 8))
            {
                new1.x = PosA[i].x;
                new1.y = PosA[i].y + 1;
                arr.push_back(new1);
            };
            if ((Board[PosA[i].x][PosA[i].y - 1] * k <= 0) && (PosA[i].y - 1 >= 0))
            {
                new1.x = PosA[i].x;
                new1.y = PosA[i].y - 1;
                arr.push_back(new1);
            };
        }
        return arr;
    }
    void undo(){
        cout<<"UNDO? "<<endl;
        bool y;
        cin>>y;
        Undo R;
        while(y==true&&!U.empty()){
            turn=!turn;
            R=U.top();
            cout<<"<<"<<R.PorC<<" "<<R.i<<" "<<R.begin.x<<R.begin.y<<R.end.x<<R.end.y<<endl;
            if (R.PorC==-1){
                Board[R.begin.x][R.begin.y]=Player1.PosB[R.i].value;
                Board[R.end.x][R.end.y]=0;
                Player1.PosB[R.i].x=R.begin.x;
                Player1.PosB[R.i].y=R.begin.y;       
                Player1.Player[R.i]->setP(R.begin.x,R.begin.y);
               
                U.pop();
                if (U.empty()) {
                    y=false;
                    break;
                }
                R=U.top();
                if (R.PorC==1&&R.end.x==Pdie.x){
                    Player2.Computer[R.i]->alive();
                    Player2.PosA[R.i].value=Player2.Computer[R.i]->getValue();
                    Board[Player2.PosA[R.i].x][Player2.PosA[R.i].y]=Player2.PosA[R.i].value;
                    U.pop();
                }
                y= false;

            }
            else if (R.PorC==1){
                Board[R.begin.x][R.begin.y]=Player2.PosA[R.i].value;
                Board[R.end.x][R.end.y]=0;
                Player2.PosA[R.i].x=R.begin.x;
                Player2.PosA[R.i].y=R.begin.y;       
                Player2.Computer[R.i]->setP(R.begin.x,R.begin.y);
                U.pop();
                if (U.empty()) {
                    y=false;
                    break;
                }
                R=U.top();
                if (R.PorC==-1&&R.end.x==Pdie.x){
                    Player1.Player[R.i]->alive();
                    Player1.PosB[R.i].value=Player1.Player[R.i]->getValue()*Player1.Player[R.i]->getIndex();
                    Board[Player1.PosB[R.i].x][Player1.PosB[R.i].y]=Player1.PosB[R.i].value;
                    U.pop();
                }
                y=false;

            }
        }


    }
    void Move(){
        if (turn==true){
        int j, x1, y1;
        banco();
        cin >> j;
        vector<Location> P = ValidMove(j, Board, Player1.PosB);
        for (int i = 0; i < P.size(); i++)
        {
            cout << endl << P[i].x << " " << P[i].y;
        }
        cout << endl
            << "dich: ";
        cin >> x1 >> y1;
        if (Board[x1][y1]>0){
            for (int i=0;i<16;i++){
                if (Board[x1][y1] == Player2.PosA[i].value && Player2.PosA[i].x == x1 && Player2.PosA[i].y == y1){
                    Player2.PosA[i].value = -1;
                    Player2.Computer[i]->die();
                    //undo
                    Undo m;
                    m.i=i;
                    m.PorC=1;
                    m.begin.x=x1;
                    m.begin.y=y1;
                    m.end=Pdie;
                    U.push(m);
                    

                    break;

                }
            }
        }
        // kiem tra phong hau
        if (Player1.PosB[j].value==-10 && y1==0){
            Player1.PosB[j].value=-90;
            Player1.Player[j]->BecomeQueen();
        }
        //undo
        Undo n;
        n.i=j;
        n.PorC=-1;
        n.begin.x=Player1.PosB[j].x;
        n.begin.y=Player1.PosB[j].y;
        n.end.x=x1;
        n.end.y=y1;
        U.push(n);

        Board[x1][y1] = Player1.PosB[j].value;
        Board[Player1.PosB[j].x][Player1.PosB[j].y] = 0;
        Player1.PosB[j].x = x1;
        Player1.PosB[j].y = y1;
        Player1.Player[j]->setP(x1, y1);

        turn=!turn;
        }
    else if (turn==false){
        int j, x1, y1;
        banco();
        cin >> j;
        vector<Location> P = ValidMove(j, Board, Player2.PosA);
 
        for (int i = 0; i < P.size(); i++)
        {
            cout << endl << P[i].x << " " << P[i].y;
        }
        cout << endl
            << "dich: ";
        cin >> x1 >> y1;
        if (Board[x1][y1]<0){
            for (int i=0;i<16;i++){
                if (Board[x1][y1] == Player1.PosB[i].value && Player1.PosB[i].x == x1 && Player1.PosB[i].y == y1){
                    Player1.PosB[i].value = -1;
                    Player1.Player[i]->die();

                    //undo
                    Undo m;
                    m.i=i;
                    m.PorC=-1;
                    m.begin.x=x1;
                    m.begin.y=y1;
                    m.end=Pdie;
                    U.push(m);

                    break;
                }
            }
        }
        // kiem tra phong hau
        if (Player2.PosA[j].value==10 && y1==7){
            Player2.PosA[j].value=90;
            Player2.Computer[j]->BecomeQueen();
        }
        //undo
        Undo n;
        n.i=j;
        n.PorC=1;
        n.begin.x=Player2.PosA[j].x;
        n.begin.y=Player2.PosA[j].y;
        n.end.x=x1;
        n.end.y=y1;
        U.push(n);

        Board[x1][y1] = Player2.PosA[j].value;
        Board[Player2.PosA[j].x][Player2.PosA[j].y] = 0;
        Player2.PosA[j].x = x1;
        Player2.PosA[j].y = y1;
        Player2.Computer[j]->setP(x1, y1);

        turn=!turn;
    }

    }

};
int main(){
    GameModePvP G;
    G.begin();
    G.turn=true;
    int i=0;
    while (i++<5)
    {
        G.Move();
        
    }
    while (true){
        G.undo();
        G.banco();
    }
    
}