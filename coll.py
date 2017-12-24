import os
path='/home/manishankar/Desktop/Placements/leetcode submissions/algorithms/'

l=os.listdir(path)
f=open('./leetCodes.cpp','a')
for i in l:
	content=open(path+i).read()
	content='\n'+content
	head='//'+ i
	f.write('\n')
	f.write(head)
	f.write('\n\n')
	f.write(content)
	f.write('\n')

f.close()

#  7573