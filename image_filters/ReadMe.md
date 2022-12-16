#Introduction
***Here I implemented both tasks, Sobel filter, and Orange color filter***<br>
***I combined the two tasks in one class named it Filters***<br>
***So we have one project to run both tasks***

#Note
You may be would have to add your paths to ***CMAKE_C_COMPILER*** and 
***CMAKE_CXX_COMPILE*** in CMakeLists.txt

# Dependecies

1.   ***openCV:*** I used open cv to just read and write images.

#Run


1.   Download and extact the file

    *   ```unzip image_filters.zip```
    *   ```cd image_filters```

2. ```cmake .``` or cmake ```CMakeLists.txt```

3. ```make``` 

4. Run this if you want to the default image and the default task (Sobel Filter)

  *   ```./ImageFilters ``` 



5. If you want to run on a different image 
  *  ```./ ImageFilters path_to_image```

6. If you want to run on a (Orange Color Removal) task 
  *  ```./ ImageFilters path_to_image color```
  
  Run the next to do Orange Color Removal with the default image
  *  ```./ ImageFilters "" color``` 

