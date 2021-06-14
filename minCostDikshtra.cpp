// https://www.youtube.com/watch?v=VSKkW1JsXr0&t=526s
struct Point {
  public:
  int x;
  int y;
  int cost;
};

struct comp {
    bool operator()(Point const& p1, Point const& p2)
    {
        return p1.cost > p2.cost;
    }
};
 
// R D L U
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int Solution::solve(int row, int column, vector<string> &mat) {

    //all for possilbe directions
    string s="RDLU";
    
    // to store distance 
    vector<vector<int>> dist(row,vector<int> (column,INT_MAX-1));
    //to get minimum cost path  
    priority_queue<Point,vector<Point>,comp> pq;

    //push the initial co-ordinates
    pq.push({0,0,0});
    dist[0][0]=0;
    
    while(!pq.empty()){
        //minimum cost co-ordinates
        Point currentPoint= pq.top();
        pq.pop();
        
        // reach the destination
        if(currentPoint.x==row-1 && currentPoint.y==column-1) return dist[currentPoint.x][currentPoint.y];
      
        //go to all 4 possible directions
        for(int i=0;i<4;i++){
            
            //new position
            int newx=currentPoint.x+dx[i];
            int newy=currentPoint.y+dy[i];

            int cost=dist[currentPoint.x][currentPoint.y];
            // increase cost by 1 (if path not matches)
            if(s[i]!=mat[currentPoint.x][currentPoint.y]) cost++;
            
            //check boundary condition and cost
            if((newx>=0 && newy>=0 && newx<row && newy<column) && cost<dist[newx][newy]){
                pq.push({newx,newy,cost});
                dist[newx][newy]=cost;
            }
            
        }
        
    }
    
    return dist[row-1][column-1];
    
}