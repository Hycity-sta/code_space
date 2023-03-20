file = open("test.txt",'w') #用写入方式来打开文件
file.write('i love you') #写入文件, 但是这个会覆盖掉原文件的内容
file.close() #关闭文件
file = open('test.txt')#以只读方式打开文件
txt = file.read()#读文件内部的内容
print("i want to tell you:\n%s" % txt)#输出文件内部的内容
