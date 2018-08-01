
#include<iostream >
#include <queue>
#include <vector>
using namespace std;
int row[4]={0,0,-1,1};
int col[4] ={-1,1,0,0};
class state{

public:
int pb[3][3];
int x;
int y;

};

bool isequal (state is ,state rs){
    bool result = true;
  for (int i=0;i<3;i++){

    for(int j=0; j<3 ;j++){

        if (is.pb[i][j]!=rs.pb[i][j]){
            result=false;
            break;
        }

    }

  }
  return result;
}
state goal ;

vector<state> visited;
void setarray(int ar[3][3],int ar2[3][3]){
for (int i=0;i<3;i++){

     for (int j=0;j<3;j++){

        ar[i][j]=ar2[i][j];


     }

}


}

void printarray(state state){

for (int i=0;i<3;i++){

      for(int j=0;j<3;j++)
    {

        cout << state.pb[i][j]<<" ";
    }

    cout<<endl;
}
cout << endl;


}


bool issafe(int x,int y){

//cout << x << " " << y;


if (x>=0&& x<3 && y>=0 && y<3){


 return true;



}
return false;

}
void  solve(state initial)
{

    queue<state> q;
    vector <state> visited;
    q.push(initial);

    while (!q.empty()){
        state current =q.front();
        visited.push_back(current);
        q.pop();
        printarray(current);
        if( isequal(current,goal)){

            cout<<"found";
            return;

        }
        for (int i=0;i<4;i++){
            if (issafe(current.x+row[i],current.y+col[i])){
               // cout << "OK";
                int x=current.x;
                int y=current.y;
                int temp=current.pb[x][y];
                int nwx=current.x+row[i];
                int nwy =current.y+col[i];
                current.pb[x][y]=current.pb[nwx][nwy];
                current.pb [nwx][nwy]= temp;

                state child;
                setarray(child.pb,current.pb);
                child.x=nwx;
                child.y=nwy;




                  temp=current.pb[x][y];
                nwx=current.x+row[i];
                 nwy =current.y+col[i];
                current.pb[x][y]=current.pb[nwx][nwy];
                current.pb [nwx][nwy]= temp;

                 q.push(child);

            }

        }
    }
}

int main(){
     state initial;
     initial.pb[0][0]=1;
     initial.pb[0][1]=2;
     initial.pb[0][2]=3;

     initial.pb[1][0]=6;
     initial.pb[1][1]=0;
     initial.pb[1][2]=4;

     initial.pb[2][0]=8;
     initial.pb[2][1]=7;
     initial.pb[2][2]=5;



     initial.x=1;
     initial.y=1;


     goal.pb[0][0]=1;
     goal.pb[0][1]=2;
     goal.pb[0][2]=3;

     goal.pb[1][0]=8;
     goal.pb[1][1]=0;
     goal.pb[1][2]=4;

     goal.pb[2][0]=7;
     goal.pb[2][1]=6;
     goal.pb[2][2]=5;

     solve(initial);
    return 0;
}
