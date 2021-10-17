#include <iostream>
#include <vector>

using namespace std;

class Coordinate{
    public:
        int row;
        int col;
        Coordinate(int r, int c){
            row = r;
            col = c;
        }
};


class RobotInGrid{
    public:
        bool grid[3][4] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0}
        };

        bool failed[3][4] = {0};


        bool findPath(int r, int c,  vector<Coordinate> * path){


            // if there is a obstacle
            if (grid[r][c] == 1 || failed[r][c] == 1)
            {
                return false;
            }
            

            if (r < 0 || c < 0)
            {
                return false;
            }

            bool startTile = (r == 0) && (c == 0);
            
            if (startTile || findPath(r, c-1, path) || findPath(r-1, c, path))
            {
                Coordinate tile(r,c); 
                path->push_back(tile);
                return true;
            }
            
            failed[r][c] = 1;
            return false;

        }

};


int main(){

    vector<Coordinate> * path = new vector<Coordinate>();
    RobotInGrid * RG = new RobotInGrid();

    bool found = RG->findPath(2, 3, path);
    string str = found ? "found" : "not found"; 
    cout << "path " << str << endl;

    for (int i = 0; i < path->size(); i++)
    {
        cout << path->at(i).row << " , " << path->at(i).col << endl;
    }
    


}