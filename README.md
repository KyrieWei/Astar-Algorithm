# Astar-Algorithm

> A widget application to implement the Astar algorithm, built with Qt.



### About Astar-Algorithm

A* is a computer algorithm that is widely used in pathfinding and graph traversal, the process of plotting an efficiently directed path between multiple points, called nodes. It enjoys widespread use due to its performance and accuracy.  --Wikipedia

### About the application

The main interface of the application is as followed:

![Astar](https://github.com/kyriewei/Astar-Algorithm/raw/master/image/Astar.png)

It is easy for users to understand the features of this application. In the middle of the mainwindow is a 40×40 button array. I divide the map into 1600 cubes. It is just like pixel but enlarged. We could set the start point after clicking the starPoint button, block points after clicking the BlockPoint button and final point after clicking the finalPoint button. Then, we will get the best road after the findRoad button being clicked. Of course we could start the new game aferter the newGame button being clicked.

The final result after running the  application is like this:

![astarresult](/home/kyriewei/图片/astarresult.png)



### Algorithms

> The most important part of the project  is A* algorithm.

Here is the steps of A* algorithm:

1. add start point to OpenList.

2. repeat the following procedures:

   ​	a.  traverse OpenList, find the node which has the smallest F, set it as the current node to be 					 		   

   ​	     handled with.

   ​	b.  move the current node into ClosedList.

   ​	c.   check each of the 8 cubes around the current cube:

   ​		**◇**    if the cube is unreachable  or in ClosedList, ignore it. Otherwise, do as followed.

   ​		**◇**    if the cube is not in OpenList, add it and set  current cube as the parent of this cube.

   ​			Record G, H, and F value of this cube.

   ​		**◇**    if the cube is in OpenList, check if the current path is the best or not judging by value G. 

   ​			The samller G means the better path. If it is, then set the current cube as its parent and 		 

   ​			reset G, F value.

   ​	d.   stop. When

   ​		**◇**    the final point is added into  OpenList, then we get the optimal path. Or

   ​		**◇**  	fail to find the final point and OpenList is empty. 

3. save the path. Start at the final point, and work backwards moving from one cube to its parent. This wil eventually take us back to the start point, and that's our path.

   > A* algorithm details	

The key to determine which cube to use when figuring out the path is the following equation:

F = G + H

where

G = the movement cost to move from the start point to a given cube on the grid, following the path generated to get there.

H is estimated by the Manhattan method, where we calculate the total number of squares moved horizontally and vertically to reach the final point from the current cube, ignoring diagonal movement. We then multiply the total by 10. 

F is calculated by adding G and H.

#### References

**Model** Class

| Class | Description                     |
| ----- | ------------------------------- |
| AI    | AI contains the A* algorithm    |
| cube  | cube is the model of the button |
| list  | implement link list             |

**View**  Class

| Class      | Description                |
| ---------- | -------------------------- |
| mybutton   | custom button of buttonArr |
| mainwindow | display the UI             |



