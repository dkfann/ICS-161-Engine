/ This is an example of how to use the sprite control file

/ In your code, you can create a Sprite by saying
/ Sprite s = Sprite("this file", renderer);

/ Slashes may be used for comments


/ f= or file= or FILE= or F= will specify a file in the same directory
/ as the control file, additional backslashes and .. can be used to specify other directories
/ For example: ..\myimg.png will point to the image called myimg.png above
/ the folder of this file
/ 
/ The same image can be used for different sequences
/ All subsequent frames will use this file
/ It is possible to change the file by saying f= again

/ There cannot be a space between the = and the filename as it is legal to have
/ leading spaces in filenames

f=res\y01uPOi.png

/ A colon (:) is used to specify a sequence name, it is possible to
/ reuse a sequence name in order add more frames to that sequence
/ For example, ":walk up" will make all subsequent frames map to the "walk up" sequence
/ Notice how the colon is not included in the sequence name

:walk up

/ The frame format is as follows:
/ The parameters in square brackets are optional
/ X, Y, WIDTH, HEIGHT, [X OFFSET, Y OFFSET], [DURATION OR LENGTH]
/ X OFFSET and Y OFFSET are used to render the frame from a point other than it's center
/ For example, an X OFFSET of WIDTH/2 and a Y OFFSET of HEIGHT/2 will render the frame at its center

/ X   Y   W   H OFFX OFFY LEN
  0 , 0, 32, 64, 16, 32, 30
 32 , 0, 32, 64, 16, 32,  3
 64 , 0, 32, 64, 16, 32,  3
 96 , 0, 32, 64, 16, 32,  3
128 , 0, 32, 64, 16, 32,  3
160 , 0, 32, 64, 16, 32,  3
192 , 0, 32, 64, 16, 32,  3

/ A LEN of 0 or lesser means that the frame lasts forever
224 , 0, 32, 64, 16, 32, 0
                  
                  / Leading and trailing whitespaces are allowed
     :walk down

/ As stated before, it is possible to change the file at any time
f=res\Untitled.png

0,192,32,64,3
32,192,32,64,3
64,192,32,64,3
96,192,32,64,3


f=res\y01uPOi.png

128,192,32,64,3
160,192,32,64,3
192,192,32,64,3
224,192,32,64,3

/ A number by itself can be used to loop a smaller portion of the sequence
/ 
/ For example, a run sequence might have some startup frames before
/ the actual loop starts
/
/ The number that is put here tells the length of the loop
/ A value of 0 has no effect
/ A value of 1 or lesser has the same effect as creating a frame with infinite length
12

:walk left

	0,128,32,64,3
	32,128,32,64,3
	64,128,32,64,3
	96,128,32,64,3
	128,128,32,64,3
	160,128,32,64,3
	192,128,32,64,3
	224,128,32,64,3

:walk right

0,64,32,64,3
32,64,32,64,3
64,64,32,64,3
96,64,32,64,3
128,64,32,64,3
160,64,32,64,3
192,64,32,64,3
224,64,32,64,3