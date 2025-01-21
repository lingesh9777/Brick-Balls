#include<iostream>
#include<vector>
using namespace std;

class BrickBalls{
	
	vector<vector<char>>grid;
	int N;
	public:
	BrickBalls(int N){
		this->N = N;
		grid.resize(N);
		for(int row = 0; row < N; row++){
			grid[row].resize(N);
			for(int col = 0; col < N; col++){
				if(row == 0 || col == 0 || col == N-1){
					grid[row][col] = 'W';
				}
				else if(row == N-1 && col > 0 && col < N-1){
					grid[row][col] = 'G';
				}
				else{
					grid[row][col] = ' ';
				}
			}
		}
		grid[N-1][N/2] = 'o';
	}
	
	void setBricks(vector<pair<int,int>>bricks,vector<char>bst){
		for(int row = 0; row < bricks.size(); row++){
			grid[bricks[row].first][bricks[row].second] = bst[row];
		}
	}
	
	void displayGame(){
		for(int row = 0; row < N; row++){
			for(int col = 0; col < N; col++){
				cout<<grid[row][col]<<" ";
			}
			cout<<endl;
		}
	}
	
	void blastRow(int blast_row){
		for(int col = 1; col < N-1; col++){
			grid[blast_row][col] = ' ';
		}
	}
	
	void blastsurr(int blast_row, int blast_col){
		vector<int>rdir = {-1,-1,-1,0,0,0,1,1,1};
		vector<int>cdir = {-1,0,1,-1,0,1,-1,0,1};
		int row,col;
		grid[blast_row][blast_col] = ' ';
		for(int ind = 0; ind < 8; ind++){
			row = blast_row + rdir[ind];
			col = blast_col + cdir[ind];
			if(row>0 && row<N-1 && col > 0 && col<N-1 && grid[row][col] != ' '){
				grid[row][col] = ' ';
			}
		}		
	}
	
	void moveStraight(int &brow, int &bcol){
		for(int row = brow-1; row > 0; row--){
			if(grid[row][bcol] != ' '){
				if(grid[row][bcol] == '1'){
					grid[row][bcol] = ' ';
				}
				else if(grid[row][bcol] == 'B'){
					blastRow(row);
				}
				else if(grid[row][bcol] == 'S'){
					blastsurr(row,bcol);
				}
				else{
					grid[row][bcol]-=1;
				}
				break;
			}
		}
	}
	
	void changeBall(int &brow, int &bcol, int row, int col){
		
		if(grid[row][col] == 'B'){
			blastRow(row);
		}
		else if(grid[row][col] == 'S'){
			blastsurr(row,col);
		}
		else if(grid[row][col] == '1'){
			grid[row][col] = ' ';
		}
		else{
			grid[row][col]--;
		}
		grid[brow][bcol] = 'G';
		grid[brow][col] = 'o';
		bcol = col;
	}
	

	bool moveLeft(int &brow, int &bcol){
		for(int row = brow-1,col = bcol-1; row > 0 && col >=0; row--,col--){
			if(grid[row][col] == 'W'){
				for(int c = col+1; c<N-1; c++){
					if(grid[row][c] != ' '){
						changeBall(brow,bcol,row,c);
						return 0;
					}
				}
				return 1;
	      	}
	      	else if(grid[row][col] != ' '){
				changeBall(brow,bcol,row,col);
				return 0;
			}				
		}
		return 0;
	}
	
	bool moveRight(int &brow, int &bcol){
		for(int row = brow-1,col = bcol+1; row > 0,col <= N-1; row--,col++){
			if(grid[row][col] == 'W'){
				for(int c = col-1; c > 0; c--){
					if(grid[row][c] != ' '){
						changeBall(brow,bcol,row,c);
						return 0;
					}
				}
				return 1;
			}
			else if(grid[row][col] != ' '){
				changeBall(brow,bcol,row,col);
				return 0;
			}
		}
		return 0;
	}
	
	bool gameResult(){
		for(int row = 1; row < N-1; row++){
			for(int col = 1; col < N-1; col++){
				if(grid[row][col] != ' '){
					return 0;
				}
			}
		}
		return 1;
	}
	
	void players(){
		int ball_count = 3;
		int curr_row = N-1,curr_col = N/2;
		string input;		
		displayGame();
		while(ball_count){
			cout<<"Enter the direction in which the ball need to traverse(ST/LD/RD) :";
			cin>>input;
			if(input == "ST"){
			    moveStraight(curr_row,curr_col);	
			}
			else if(input == "LD"){
				if(moveLeft(curr_row,curr_col)){
					ball_count--;	
					changeBall(curr_row,curr_col,N-1,N/2);		
					curr_col = N/2;					
				}
			}
			else if(input == "RD"){
				if(moveRight(curr_row,curr_col)){
					ball_count--;
					changeBall(curr_row,curr_col,N-1,N/2);
					curr_col = N/2;
				}
			}
			else{
				cout<<"Invalid choice";
			}
			displayGame();
		    cout<<"Ball count:"<<ball_count<<endl;
		    if(gameResult()){
		    	cout<<"Congratulations..You\'ve Won!";
		    	return;
			}
	    }
		cout<<"Oops! Try Again!";		
	}	
};

int main(){
	BrickBalls Gamer1(7);
//	Gamer1.displayGame();
	vector<pair<int,int>>bricks;
	vector<char>bst;
	char choice = 'Y';
	int row,col;
	char bs;
	while(choice == 'Y'){
		cout<<"Enter the brick\'s position and the brick type:";
		cin>>row>>col;
		cin.ignore();
		cin>>bs;
		bricks.push_back({row,col});
		bst.push_back(bs);
		cout<<"Do you want to continue(Y or N)?";
		cin>>choice;
	}
	Gamer1.setBricks(bricks,bst);
	//Gamer1.displayGame();
	Gamer1.players();
	
}
