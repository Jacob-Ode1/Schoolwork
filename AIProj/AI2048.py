# 2048.py

# importing the logic.py file
# where we have written all the
# logic functions used.
import logic
def AI_Choice(mat,n)		#first parameter is the board state, second is the number of layers
	st=[]
	st.append(AI_Choice(Automove('w',mat),n-1)
	st.append(AI_Choice(Automove('a',mat),n-1)
	st.append(AI_Choice(Automove('s',mat),n-1)
	st.append(AI_Choice(Automove('d',mat),n-1)'
	if(st[1]=min(st)):
		return 'a'
	if(st[2]=min(st)):
		return 's'
	if(st[3]=min(st)):
		return 'd
	return 'w'
def AI_Choose(mat,n)       
	if(n=0):
		return HStick(mat)
	st=[]
	st.append(AI_Choice(Automove('w',mat),n-1)
	st.append(AI_Choice(Automove('a',mat),n-1)
	st.append(AI_Choice(Automove('s',mat),n-1)
	st.append(AI_Choice(Automove('d',mat),n-1)
	return min(st)
		
def Automove(x,mat):
	if(x=='w'):
		mat, flag = logic.move_up(mat)
		status = logic.get_current_state(mat)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
	if(x=='a'):
		mat, flag = logic.move_left(mat)
		status = logic.get_current_state(mat)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
	if(x=='s'):
		mat, flag = logic.move_down(mat)
		status = logic.get_current_state(mat)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
	if(x=='d'):
		mat, flag = logic.move_right(mat)
		status = logic.get_current_state(mat)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
	return mat
def HStick(mat):
	c=0
	#mx=0
	for i in range(4):
		for j in range(4):
			if(mat[i][j]!=0):
				#if(mat[i][j]>mx):
				#	mx=mat[i][j]
				c+=1
	return c


mat = logic.start_game()
print("test")

while(True):
	print("test2")
	# taking the user input
	# for next step
	x = AI_Choice(mat,2)
	# we have to move up
	if(x == 'W' or x == 'w'):

		# call the move_up function
		mat, flag = logic.move_up(mat)

		# get the current state and print it
		status = logic.get_current_state(mat)

		# if game not ove then continue
		# and add a new two
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)

		# else break the loop
		else:
			break

	# the above process will be followed
	# in case of each type of move
	# below

	# to move down
	elif(x == 'S' or x == 's'):
		mat, flag = logic.move_down(mat)
		status = logic.get_current_state(mat)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
		else:
			break

	# to move left
	elif(x == 'A' or x == 'a'):
		mat, flag = logic.move_left(mat)
		status = logic.get_current_state(mat)
		print(status)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
		else:
			break

	# to move right
	elif(x == 'D' or x == 'd'):
		mat, flag = logic.move_right(mat)
		status = logic.get_current_state(mat)
		if(status == 'GAME NOT OVER'):
			logic.add_new_2(mat)
		else:
			break
	else:
		print("Invalid Key Pressed")

	# print the matrix after each
	# move.
	print(mat)
print(status)





