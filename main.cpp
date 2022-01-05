

#include "room.h"

//1, 3, 5

int randomize(int *, int);
int create_rooms(int *, int, node*);
int agent1(int, node*, int);

int agent2(int, node *, int);

int agent3(int, node*, int);
int agent4(int, node*, int);



int main()
{

  node * room1= new node;
  int temp_num_dirt = 5;
  int select_agent= 4;

  int * dirt_loc =NULL;
  dirt_loc= new int[temp_num_dirt + 1];

  int start_loc = randomize(dirt_loc, temp_num_dirt);
  create_rooms(dirt_loc, temp_num_dirt, room1);
  //call function to add rand dirt piles into correct squares

  //have if loop to only call 1 of 4 agent functions
  //call function to start preforming cleaning agents

  if(select_agent == 1){
    agent1(start_loc, room1, temp_num_dirt);
  }

  if(select_agent == 2){
    agent2(start_loc, room1, temp_num_dirt);
  }

  if(select_agent == 3){
    agent3(start_loc, room1, temp_num_dirt);
  }
  if(select_agent == 4){
    agent4(start_loc, room1, temp_num_dirt);
  }


}

int randomize(int * dirt_loc, int temp_num_dirt){

  srand((unsigned int)time(NULL));

  int start_loc = rand() % 9 + 1;
  int temp;
  int n=0;

  //allocate memory based on number of dirt piles

  dirt_loc[0] = rand() % 9 + 1;
  int index=1;


  //if more than 1, enter for
  for(int i = 0; i < temp_num_dirt; i++) {

    //each time, search array to compare the new rand value -
    // if it is a repeat enter a while loop until answer is unique.

    temp = rand() % 9 + 1;
    cout<<"this is temp"<<temp<<'\n';

    while(n < index){

      if(temp == dirt_loc[n]){
        temp = rand() % 9 + 1;
        n = 0;
      }

      else {

        n++;

      }
    }

    dirt_loc[index] = temp;
    index++;

  }

  cout<<"these are dirt locations";

  cout<< dirt_loc[0]<<'\n';
  /*
  cout<< dirt_loc[1];
  cout<< dirt_loc[2];
  cout<<dirt_loc[3];
  cout<<dirt_loc[4]<< '\n';*/


  cout<<"start location :" << start_loc;

  return start_loc;

}



int create_rooms(int * dirt_loc, int temp_num_dirt, node * temp1){


  //node * temp1 = new node;
  node * temp2 = new node;
  node * temp3 = new node;
  node * temp4 = new node;
  node * temp5 = new node;
  node * temp6 = new node;
  node * temp7 = new node;
  node * temp8 = new node;
  node * temp9 = new node;

  temp1->id = 1;
  temp1->dirt = 0;
  temp1->left = NULL;
  temp1->right = temp2;
  temp1->down = temp6;
  temp1->up = NULL;


  temp2->id = 2;
  temp2->dirt = 0;
  temp2->left = temp1;
  temp2->right = temp3;
  temp2->down = temp5;
  temp2->up = NULL;


  temp3->id = 3;
  temp3->dirt = 0;
  temp3->left = temp2;
  temp3->right = NULL;
  temp3->down = temp4;
  temp3->up = temp3;


  temp4->id = 4;
  temp4->dirt = 0;
  temp4->left = temp5;
  temp4->right = NULL;
  temp4->down = temp9;
  temp4->up = temp3;


  temp5->id = 5;
  temp5->dirt = 0;
  temp5->left = temp6;
  temp5->right = temp4;
  temp5->down = temp8;
  temp5->up = temp2;


  temp6->id = 6;
  temp6->dirt = 0;
  temp6->left = NULL;
  temp6->right = temp5;
  temp6->down = temp7;
  temp6->up = temp1;


  temp7->id = 7;
  temp7->dirt = 0;
  temp7->left = NULL;
  temp7->right = temp8;
  temp7->down = NULL;
  temp7->up = temp6;

  temp8->id = 8;
  temp8->dirt = 0;
  temp8->left = temp7;
  temp8->right = temp9;
  temp8->down = NULL;
  temp8->up = temp5;


  temp9->id = 9;
  temp9->dirt = 0;
  temp9->left = temp8;
  temp9->right = NULL;
  temp9->down = NULL;
  temp9->up = temp4;

  //for i < num_dirt -> traverese nodes until find dirt_loc[i] == each node
  //OR if(dirt_loc[i] ==i) { temp1->dirt = 1 etc. ...}

  for(int i=0; i<temp_num_dirt; i++){
    if(dirt_loc[i] == 1) {
      temp1->dirt = 1;
    }
    if(dirt_loc[i] == 2) {
      temp2->dirt = 2;
    }
    if(dirt_loc[i] == 3) {
      temp3->dirt = 3;
    }
    if(dirt_loc[i] == 4) {
      temp4->dirt = 4;
    }
    if(dirt_loc[i] == 5) {
      temp5->dirt = 5;
    }
    if(dirt_loc[i] == 6) {
      temp6->dirt = 6;
    }
    if(dirt_loc[i] == 7) {
      temp7->dirt = 7;
    }
    if(dirt_loc[i] == 8) {
      temp8->dirt = 8;
    }
    if(dirt_loc[i] == 9) {
      temp9->dirt = 9;
    }
  }



  return 0;

}

int agent1(int start_loc, node * room1, int num_dirt){

  int moves=0;
  bool found_start =0;
  bool reached_end=0;
  node * temp=room1;
  bool move_right=0;

  cout<<'\n'<<"in agent 1"<<'\n';
  int n=0;

  while(found_start == 0 && n<10){


    if( temp->id == start_loc){
      found_start=1;
    }
    else{
      if(temp->right && move_right == 0){
        temp=temp->right;
      }
      else if(temp->left && move_right == 1){
        temp=temp->left;
      }
      else if(temp->down){
        temp=temp->down;
        if(move_right ==0){
          move_right =1;

        }
        else if(move_right == 1){
          move_right = 0;
        }
      }


    }
    n++;
  }
  /*
     while(moves < 9){



     }*/
  cout<<'\n'<<"starting node : " <<temp->id;
  cout<<'\n'<<"in while, temp = "<<temp->id<<'\n';

  n=0; 
  int m=0;
  while(n != num_dirt){



    if(temp->dirt == 1){
      temp->dirt=0;

      n++;
      // found_start=1;
    }

    // else{
    if(temp->right && move_right == 0){
      temp=temp->right;
      m++;
    }
    else if(temp->left && move_right == 1){
      temp=temp->left;
      m++;
    }
    else if(temp->down){
      temp=temp->down;
      m++;
      if(move_right ==0){
        move_right =1;

      }
      else if(move_right == 1){
        move_right = 0;
      }
    }
    else if(!temp->right || !temp->left){
      if(!temp->down){
        temp=temp->up;
        m++;
        temp=temp->up;
        m++;
        move_right=1;

      }
      //  }


  }
  }

  cout<<"number of moves :" << m <<'\n';


}


int agent2(int start_loc, node * room1, int num_dirt){

  int moves=0;
  bool found_start =0;
  bool reached_end=0;
  node * temp=room1;
  bool move_right=0;

  cout<<'\n'<<"in agent 2"<<'\n';
  int n=0;

  while(found_start == 0 && n<10){


    if( temp->id == start_loc){
      found_start=1;
    }
    else{
      if(temp->right && move_right == 0){
        temp=temp->right;
      }
      else if(temp->left && move_right == 1){
        temp=temp->left;
      }
      else if(temp->down){
        temp=temp->down;
        if(move_right ==0){
          move_right =1;

        }
        else if(move_right == 1){
          move_right = 0;
        }
      }


    }
    n++;
  }
      cout<<'\n'<<"starting node : " <<start_loc;

      cout<<'\n'<<"in while, temp = "<<temp->id<<'\n';


  n=0; 
  int m=0;
  int left = 1;
  int right = 2;
  int down = 3;
  int up=4;
  int direction = 0;

  while(n != num_dirt){

    direction = rand () % 4 + 1;

    if(temp->dirt == 1){
      temp->dirt = 0;
      n++;
    }

    if(direction == 1 && temp->left){

      temp=temp->left;
    }

    if(direction == 2 && temp->right){

      temp=temp->right;
    }


    if(direction == 3 && temp->down){

      temp=temp->down;
    }


    if(direction == 4 && temp->up){

      temp=temp->up;
    }

    m++;
  }

  cout << "total number of sucks : "<<n<<'\n'<<"total number of moves: "<<m<<'\n';




  return 1;
}

int agent3(int start_loc, node * room1, int num_dirt){
  int moves=0;
  bool found_start =0;
  bool reached_end=0;
  node * temp=room1;
  bool move_right=0;

  cout<<'\n'<<"in agent 3"<<'\n';
  int n=0;

  while(found_start == 0 && n<10){


    if( temp->id == start_loc){
      found_start=1;
    }
    else{
      if(temp->right && move_right == 0){
        temp=temp->right;
      }
      else if(temp->left && move_right == 1){
        temp=temp->left;
      }
      else if(temp->down){
        temp=temp->down;
        if(move_right ==0){
          move_right =1;

        }
        else if(move_right == 1){
          move_right = 0;
        }
      }


    }
    n++;
  }
      cout<<'\n'<<"starting node : " <<temp->id;

      cout<<'\n'<<"in while, temp = "<<temp->id<<'\n';
  /*
     while(moves < 9){



     }*/

  n=0; 
  int probability=0;
  int m=0;
  int d=0;
  int nod=0;
  int yesd=0;
  while(n != num_dirt){


    probability = rand() % 4 + 1;

    if(probability <= 4 && probability > 1){

      if(temp->dirt == 1){
        temp->dirt=0;
        n++;
        d++;


      }
    }

    else if(probability == 1){
      if(temp->dirt ==1){
        yesd++;
      }
      else{
      temp->dirt = 1;
      num_dirt++;
      nod++;
      }
      


    }

    // found_start=1;


    // else{
    if(temp->right && move_right == 0){
      temp=temp->right;
      m++;
    }
    else if(temp->left && move_right == 1){
      temp=temp->left;
      m++;
    }
    else if(temp->down){
      temp=temp->down;
      m++;
      if(move_right ==0){
        move_right =1;

      }
      else if(move_right == 1){
        move_right = 0;
      }
    }
    else if(!temp->right || !temp->left){
      if(!temp->down){
        temp=temp->up;
        m++;
        temp=temp->up;
        m++;
        move_right=1;

      }
      //  }


  }
  }

    cout<<'\n'<<"starting node : " <<temp->id;

    cout<<'\n'<<"in while, temp = "<<temp->id<<'\n';

    cout<<"number of moves: = " <<m <<'\n'<<"number of dirt sucked"<<d<<'\n';
    cout<<"numer of dirt missed : "<<nod <<'\n'<<"number of dirt dropped : "<<yesd<<'\n';

  return 1;

}

int agent4(int start_loc, node * room1, int num_dirt){
  int moves=0;
  bool found_start =0;
  bool reached_end=0;
  node * temp=room1;
  bool move_right=0;

  cout<<'\n'<<"in agent 4"<<'\n';
  int n=0;

  while(found_start == 0 && n<10){


    if( temp->id == start_loc){
      found_start=1;
    }
    else{
      if(temp->right && move_right == 0){
        temp=temp->right;
      }
      else if(temp->left && move_right == 1){
        temp=temp->left;
      }
      else if(temp->down){
        temp=temp->down;
        if(move_right ==0){
          move_right =1;

        }
        else if(move_right == 1){
          move_right = 0;
        }
      }



    }
    n++;
  }


  n=0; 
  int m=0;
  int left = 1;
  int right = 2;
  int down = 3;
  int up=4;
  int direction = 0;;
  int probability = 0;

  int d=0;
  int nod=0;
  int yesd=0;

  while(n != num_dirt){

    direction = rand () % 4 + 1;
    probability=0;


    ///////////////////////////

    ///////////////////////   
    probability = rand() % 4 + 1;

    if(probability <= 4 && probability > 1){

      if(temp->dirt == 1){
        temp->dirt=0;
        n++;
        d++;

      }

    }

    else if(probability == 1){
      if(temp->dirt ==1){
        yesd++;
      }
      else{
      temp->dirt = 1;
      num_dirt++;
      nod++;
      }
      


    }


    if(direction == 1 && temp->left){

      temp=temp->left;
      m++;
    }

    if(direction == 2 && temp->right){

      temp=temp->right;
      m++;
    }


    if(direction == 3 && temp->down){

      temp=temp->down;
      m++;
    }


    if(direction == 4 && temp->up){

      temp=temp->up;
      m++;
    }

    m++;
  }


    cout<<"number of moves: = " <<m <<'\n'<<"number of dirt sucked"<<d<<'\n';
    cout<<"numer of dirt missed : "<<nod <<'\n'<<"number of dirt dropped : "<<yesd<<'\n';
  return 1;


}
