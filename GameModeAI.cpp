
#include "Manage.cpp"
class GameModeAI
{

public:
    GameModeAI(){};
    

    // tao nguoi choi 
    
    ManageAI AI;
    ManagePlayer Player;

   
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
        AI.begin();
        Player.begin();

        Pdie.x=-100;
        Pdie.y=-100;
        
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
    int valueCal(int arr[][8])
    {
        int sum = 0;

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                sum += arr[i][j];
            }
        }

        return sum;
    }
    void CopyMang(int begin[][8], int end[][8])
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                end[i][j] = begin[i][j];
            }
        }
    }
    void CopyPos(Pos begin[], Pos end[])
    {
        for (int i = 0; i < 16; i++)
        {

            end[i] = begin[i];
        }
    }
    int moveOder(int arr[][8], int alpha, int beta, int depth, bool turn, Pos PosA[], Pos PosB[])
    {
        if ((depth == 0) || (PosA[15].value == -1) || (PosB[15].value == -1))
            return valueCal(arr);
        if (turn == true)
        {

            for (int i = 0; i < 16; i++)
            {
                vector<Location> Parr = ValidMove(i, arr, PosA);
                int ParrL = Parr.size();
                // cout<<"y  i= "<<i<<" ParrL: "<<ParrL<<" depth: "<<depth<<endl;
                for (int j = 0; j < ParrL; j++)
                {
                    // cout<<i<<"=="<<Parr[j].x<<" "<<Parr[j].y<<arr[Parr[j].x][Parr[j].y]<<endl;
                    int b[8][8];
                    CopyMang(arr, b);
                    Pos a1[16];
                    CopyPos(PosA, a1);
                    Pos a2[16];
                    CopyPos(PosB, a2);
                    int tam = b[PosA[i].x][PosA[i].y]; // tam=PosA[i].value;

                    b[PosA[i].x][PosA[i].y] = 0;
                    // an quan
                    if (b[Parr[j].x][Parr[j].y] < 0)
                    {
                        // cout<<"=="<<b[Parr[j].x][Parr[j].y]<<endl;
                        for (int k = 0; k < 16; k++)
                        {
                            if ((a2[k].x == Parr[j].x) && (a2[k].y == Parr[j].y))
                            {
                                a2[k].value = -1;
                                break;
                            }
                        }
                    }
                    // phong hau
                    if ((Parr[j].y == 7) && (i >= 0) && (i < 8))
                    {
                        tam = 90;
                    }
                    // thay doi gia tri tren ban co
                    b[Parr[j].x][Parr[j].y] = tam;

                    // thay doi chi so quan hien tai trong mang a1(mang nhap cua PosA)
                    a1[i].x = Parr[j].x;
                    a1[i].y = Parr[j].y;
                    a1[i].value = tam;

                    int tmp = moveOder(b, alpha, beta, depth - 1, false, a1, a2);
                    // cout<<i<<" ///////////////"<<tmp<<endl;
                    if (alpha < tmp)
                    {
                        alpha = tmp;
                        if (depth == 5)
                        {

                            AI.MoveOderCurent = i;
                            AI.MoveOderNext = Parr[j];
                            // cout<<"AI.MoveOdercurent: i, "<<i<<" AI.MoveOderNext: "<<AI.MoveOderNext.x<<" "<<AI.MoveOderNext.y<<endl;
                            // console.log(moveOderCurent,moveOderNext)
                        }
                        if (alpha >= beta)
                            return alpha;
                    }
                }
            }
            return alpha;
        }
        else
        {

            for (int i = 0; i < 16; i++)
            {
                vector<Location> Parr = ValidMove(i, arr, PosB);
                int ParrL = Parr.size();
                //    cout<<"N  "<<"i= "<<i<<" ParrL: "<<ParrL<<endl;
                for (int j = 0; j < ParrL; j++)
                {
                    int b[8][8];
                    CopyMang(arr, b);
                    Pos b1[16];
                    CopyPos(PosA, b1);
                    Pos b2[16];
                    CopyPos(PosB, b2);
                    int tam = b[PosB[i].x][PosB[i].y]; // tam=PosB[i].value;
                    b[PosB[i].x][PosB[i].y] = 0;
                    // an quan
                    if (b[Parr[j].x][Parr[j].y] > 0)
                    {
                        for (int k = 0; k < 16; k++)
                        {
                            if ((b1[k].x == Parr[j].x) && (b1[k].y == Parr[j].y))
                            {
                                b1[k].value = -1;
                                break;
                            }
                        }
                    }
                    // phong hau
                    if ((Parr[j].y == 7) && (i >= 0) && (i < 8))
                    {
                        tam = -90;
                    }
                    // thay doi gia tri tren ban co
                    b[Parr[j].x][Parr[j].y] = tam;
                    // thay doi chi so quan hien tai trong mang a1(mang nhap cua PosA)
                    b2[i].x = Parr[j].x;
                    b2[i].y = Parr[j].y;
                    b2[i].value = tam;

                    int tmp = moveOder(b, alpha, beta, depth - 1, true, b1, b2);

                    if (beta > tmp)
                    {
                        beta = tmp;
                    }
                    if (alpha >= beta)
                        return beta;
                }
            }
            return beta;
        }
    }
    void undo(){
        cout<<"UNDO? "<<endl;
        bool y;
        cin>>y;
        Undo R;

        while(y==true&&!U.empty()){
            R=U.top();
         
            if (R.PorC==1){
                Board[R.begin.x][R.begin.y]=AI.PosA[R.i].value;
                Board[R.end.x][R.end.y]=0;
                AI.PosA[R.i].x=R.begin.x;
                AI.PosA[R.i].y=R.begin.y;
                AI.Computer[R.i]->setP(R.begin.x,R.begin.y);
                U.pop();
                y=true;
           
            }
            else if (R.PorC==-1)
            {
                if (R.end.x==Pdie.x){
                    Player.Player[R.i]->alive();
                    Player.PosB[R.i].value=Player.Player[R.i]->getIndex()*Player.Player[R.i]->getValue();
                    y=true;
                  
                }
                else {
                    y=false;
                }
                Board[R.begin.x][R.begin.y]=Player.PosB[R.i].value;   
                if(R.end.x!=Pdie.x) Board[R.end.x][R.end.y]=0;          
                Player.PosB[R.i].x=R.begin.x;
                Player.PosB[R.i].y=R.begin.y;       
                Player.Player[R.i]->setP(R.begin.x,R.begin.y);
                
                U.pop();
                if (y==false&&!U.empty())
                {
                    
                R=U.top();
                
                if (R.end.x==Pdie.x){
                    AI.Computer[R.i]->alive();
                    AI.PosA[R.i].value=AI.Computer[R.i]->getValue();
                    Board[AI.PosA[R.i].x][AI.PosA[R.i].y]=AI.PosA[R.i].value;
                    U.pop();

                }}
            }         
        }

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

    void MoveB()
    {
        int j, x1, y1;
        banco();
        cin >> j;
        vector<Location> P = ValidMove(j, Board, Player.PosB);
        for (int i = 0; i < P.size(); i++)
        {
            cout << endl << P[i].x << " " << P[i].y;
        }
        cout << endl
            << "dich: ";
        cin >> x1 >> y1;
        if (Board[x1][y1] > 0)
        {
            for (int i = 0; i < 16; i++)
            {
                if (Board[x1][y1] == AI.PosA[i].value && AI.PosA[i].x == x1 && AI.PosA[i].y == y1)
                {
                    AI.PosA[i].value = -1;
                    AI.Computer[i]->die();
                    //undo
                    Undo m;
                    m.i=i;
                    m.PorC=1; //quan may nen la 1
                    m.begin.x=x1;
                    m.begin.y=y1;
                    m.end=Pdie;
                    U.push(m);

                    break;
                }
            }
        }
        // kiem tra phong hau
        if (Player.PosB[j].value==-10 && y1==0){
            Player.PosB[j].value=-90;
            Player.Player[j]->BecomeQueen();
        }
        //undo

        Undo n;
        n.i=j;
        n.PorC=-1;
        n.begin.x=Player.PosB[j].x;
        n.begin.y=Player.PosB[j].y;
        n.end.x=x1;
        n.end.y=y1;
        U.push(n);

        Board[x1][y1] = Player.PosB[j].value;
        Board[Player.PosB[j].x][Player.PosB[j].y] = 0;
        Player.PosB[j].x = x1;
        Player.PosB[j].y = y1;
        Player.Player[j]->setP(x1, y1);

        
    }
    void AiEat()
    {
        for (int i = 0; i < 16; i++)
        {
            if ((Player.PosB[i].x == AI.MoveOderNext.x) && (Player.PosB[i].y == AI.MoveOderNext.y) && (Board[AI.MoveOderNext.x][AI.MoveOderNext.y] == Player.PosB[i].value))
            {
                Player.PosB[i].value = -1;
                Player.Player[i]->die();

                //undo       
                Undo m;
                m.i=i;
                m.PorC=-1; //quan nguoi nen la -1
                m.begin.x=AI.MoveOderNext.x;
                m.begin.y=AI.MoveOderNext.y;
                m.end=Pdie;
                U.push(m);
            }
        }
    }
    void MoveA()
    {
        if (Board[AI.MoveOderNext.x][AI.MoveOderNext.y] < 0)
            AiEat();
        //kiem tra phong hau
        if (AI.PosA[AI.MoveOderCurent].value==10&&AI.MoveOderNext.y==7){
            AI.PosA[AI.MoveOderCurent].value=90;
            AI.Computer[AI.MoveOderCurent]->BecomeQueen();
        }

        //undo
        Undo n;
        n.i=AI.MoveOderCurent;
        n.PorC=1;
        n.begin.x=AI.PosA[AI.MoveOderCurent].x;
        n.begin.y=AI.PosA[AI.MoveOderCurent].y;
        n.end.x=AI.MoveOderNext.x;
        n.end.y=AI.MoveOderNext.y;
        U.push(n);

        Board[AI.MoveOderNext.x][AI.MoveOderNext.y] = AI.PosA[AI.MoveOderCurent].value;
        Board[AI.PosA[AI.MoveOderCurent].x][AI.PosA[AI.MoveOderCurent].y] = 0;
        AI.PosA[AI.MoveOderCurent].x = AI.MoveOderNext.x;
        AI.PosA[AI.MoveOderCurent].y = AI.MoveOderNext.y;
        AI.Computer[AI.MoveOderCurent]->setP(AI.MoveOderNext.x, AI.MoveOderNext.y);
    }
    void show()
    {
        for (int i = 0; i < 16; i++)
        {
            cout << "x= ";
            cout << AI.PosA[i].x;
            cout << ", y=";
            cout << AI.PosA[i].y;
            cout << ", value= ";
            cout << AI.PosA[i].value;
            cout << endl;
        }
    }
};

int main()
{

    GameModeAI G;
    G.begin();
    
    while (true)
    {

        G.MoveB();
    
        G.moveOder(Board, -10000, 10000, 5, true, G.AI.PosA, G.Player.PosB);
        cout << endl
             << "END: " << G.AI.MoveOderCurent << " " << G.AI.MoveOderNext.x << " " << G.AI.MoveOderNext.y << endl;
        G.MoveA();
        G.banco();
        G.undo();
       
    }
    

  
}