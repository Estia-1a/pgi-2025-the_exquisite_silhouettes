# Daily Evaluation 13/06 - 15:34:09
You can find below how you did for each feature. 
 You should merge the pull request to keep the eval and automatically close and open the issues you have finished!
# Milestone  Tutorial
Score : 18/23 :  78%
## Detail by Feature
| Feature     | Score       | Missed tests                                                                                                           | Stdout                  |
| :---------- | :---------- | :--------------------------------------------------------------------------------------------------------------------- | :---------------------- |
| dimension   | 4/4 :  100% |                                                                                                                        |                         |
| first_pixel | 5/5 :  100% |                                                                                                                        |                         |
| tenth_pixel | 5/5 :  100% |                                                                                                                        |                         |
| second_line | 4/5 :  80%  | Second line First Pixel 21 22 23                                                                                       | second_line: 32, 32, 32 |
| print_pixel | 0/4 :  0%   | Print Pixel (0,0) : 0,0,0<br>Print Pixel (2,3) : 20,30,26<br>Print Pixel (3,2) : 30,20,19<br>Print Pixel (7,7) : 0,0,0 | <br><br><br>            |

# Milestone  statistiques
Score : 8/26 :  30%
## Detail by Feature
| Feature         | Score       | Missed tests                                                                          | Stdout                            |
| :-------------- | :---------- | :------------------------------------------------------------------------------------ | :-------------------------------- |
| max_pixel       | 4/4 :  100% |                                                                                       |                                   |
| min_pixel       | 4/4 :  100% |                                                                                       |                                   |
| min_component R | 0/3 :  0%   | Min Component R of black 8x8<br>Min Component R of white 8x8<br>Min Component 2 0 5   | min_pixel (0, 0): 0, 0, 0<br>min… |
| min_component G | 0/3 :  0%   | Min Component G of black 8x8<br>Min Component G of white 8x8<br>Min Component 2 0 5   | min_pixel (0, 0): 0, 0, 0<br>min… |
| min_component B | 0/3 :  0%   | Min Component B of black 8x8<br>Min Component B of white 8x8<br>Min Component 2 0 5   | min_pixel (0, 0): 0, 0, 0<br>min… |
| max_component R | 0/3 :  0%   | Max Component R of black 8x8<br>Max Component R of white 8x8<br>Max Component 2 0 255 | max_pixel (0, 0): 0, 0, 0<br>max… |
| max_component G | 0/3 :  0%   | Max Component G of black 8x8<br>Max Component G of white 8x8<br>Max Component 2 0 255 | max_pixel (0, 0): 0, 0, 0<br>max… |
| max_component B | 0/3 :  0%   | Max Component B of black 8x8<br>Max Component B of white 8x8<br>Max Component 2 0 255 | max_pixel (0, 0): 0, 0, 0<br>max… |

# Milestone  colors
Score : 29.900000000000002/35 :  85%
## Detail by Feature
| Feature              | Score        | Missed tests                                                                                            | Stdout           |
| :------------------- | :----------- | :------------------------------------------------------------------------------------------------------ | :--------------- |
| color_red            | 5/5 :  100%  |                                                                                                         |                  |
| color_blue           | 5/5 :  100%  |                                                                                                         |                  |
| color_green          | 5/5 :  100%  |                                                                                                         |                  |
| color_gray           | 4.9/5 :  98% |                                                                                                         |                  |
| color_invert         | 0/5 :  0%    | Invert red image<br>Invert blue image<br>Invert green Image<br>Invert white Image<br>Invert black Image | <br><br><br><br> |
| color_gray_luminance | 5/5 :  100%  |                                                                                                         |                  |
| color_desaturate     | 5/5 :  100%  |                                                                                                         |                  |

# Milestone  transform
Score : 3/15 :  20%
## Detail by Feature
| Feature           | Score       | Missed tests                                                   | Stdout   |
| :---------------- | :---------- | :------------------------------------------------------------- | :------- |
| rotate_cw         | 3/3 :  100% |                                                                |          |
| rotate_acw        | 0/3 :  0%   | rotate square image<br>rotate large image<br>rotate high image | <br><br> |
| mirror_horizontal | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_vertical   | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |
| mirror_total      | 0/3 :  0%   | mirror square image<br>mirror large image<br>mirror high image | <br><br> |

# Milestone  resize
Score : 20/60 :  33%
## Detail by Feature
| Feature        | Score         | Missed tests                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | Stdout                            |
| :------------- | :------------ | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :-------------------------------- |
| scale_nearest  | 0/20 :  0%    | scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3<br>scale_nearest 0.3<br>scale_nearest 0.5<br>scale_nearest 2<br>scale_nearest 1.3                                                                                 | <br><br><br><br><br><br><br><br>… |
| scale_bilinear | 20/20 :  100% |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |                                   |
| scale_crop     | 0/20 :  0%    | scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10<br>scale_crop 0 0 10 10<br>scale_crop 100 100 90 90<br>scale_crop 1 1 3 3<br>scale_crop 1 1 10 10 | <br><br><br><br><br><br><br><br>… |

