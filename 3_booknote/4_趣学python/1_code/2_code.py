# 如何在字符串中嵌入一个值
myscore = 1000
message = "i have %s score."
print(message % myscore)

print("\n")
# 还可以这么做
print(message % 1000)
print(message % "一百")
print("\n")
# 或者这么做
print("我的分数是%s" % "100")
print("你的分数是%s" % 200)
