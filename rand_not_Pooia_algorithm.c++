#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using std::string;
using std::endl;

int main(){
	// phase : init vars
	string items[3] = {"x","y","z"};
	int arr_len = 3; // length of1 $items array
	// no default value
	int times = 10; // number of times that loop must repeat
	int randed; // rand() function sum
	
	int xTimes = 1; // number of the times that rand returned x of $item
	int yTimes = 1; // number of the times that rand returned y of $item
	int zTimes = 1; // number of the times that rand returned z of $item
	
	int maxX = 2; // number of limit that x can be result
	int maxY = 4; // number of limit that y can be result
	int maxZ = 5; // number of limit that z can be result
	
	int xIndex = 0; // index of x in $item
	int yIndex = 1; // index of x in $item
	int zIndex = 2; // index of x in $item
	
	for(int counter=1;
	counter <= times;
	counter++){
		label:
		if(( xTimes > maxX ) &&
		( yTimes > maxY ) &&
		( zTimes > maxZ )){break;}
		
		randed = (rand()%arr_len);
		
		
		if(xTimes > maxX && randed == xIndex)
			goto label;
		if(yTimes > maxY && randed == yIndex)
			goto label;
		if(zTimes > maxZ && randed == zIndex)
			goto label;
			
		
		if(randed == 0){
			std::cout << items[randed] 
			<< " times: " << xTimes++ << endl;
		}
		if(randed == 1){
			std::cout << items[randed] 
			<< " times: " << yTimes++ << endl;
		}
		if(randed == 2){
			std::cout << items[randed] 
			<< " times: " << zTimes++ << endl;
		}
		  
		
	}
	
	std::cout << "end\n";
	
	return 0;
}
