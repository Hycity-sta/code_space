# note
- 这个笔记从列表开始,从这个笔记开始, 将笔记和代码融为一体.
- 格式要求: 将每一个知识点罗列出来, 然后配上代码块来解释

- issue:
出了点问题... 
实操代码的话就不能集成在这个文档里面了, 因为需要实践.
所以要在这个文档的目录下新建一个专门用来实践的代码.
而且还要对这个实践的代码进行一些优化, 让一个单元的知识尽可能地用一个文件来搞定, 如果没有项目依赖的话.

命名的话, 用编号来命名, 如果有依赖关系的话, 在编号后面继续用编号来命名.


## 列表比字符串强大
### 列表的形式
列表是一种python对象, 里面可以存放各种类型的元素.
列表甚至还可以在里面继续存放列表
下面的代码将创建一个列表, 里面包含了一些元素.
```python
wizard_list = ['spider', 'toe of frog', 'eye of newt', 'bat wing', 'slug butter', 'snake dandruff']
print(wizard_list)
```

```python
# 列表内存放列表
numbers = [1,2,3,4]
strings = ['I', 'kicked','my','toe','and','it','is','sore']
mylist = [numbers,strings]
print(mylist)
```


### 列表的索引
可以用[]来对列表进行索引, 索引从0开始.
下面的代码将对列表进行索引, 同时展示用:来连续索引.
:索引的时候, 不包括最后的值, 下面的示例中不包括5.
```python
print(wizard_list[2])
print(wizard_list[2:5])
```


### 对列表进行替换
可以对列表的具体位置直接赋值来进行替换操作.
下面的代码展示了列表的替换.
```python
wizard_list[2] = 'snail tongue'
print(wizard_list)
```


### 对列表进行增加
要在列表中添加元素,需要用到append函数.
下面的代码将把一个元素添加到列表的最后.
```python
wizard_list.append('bear burp')
print(wizard_list)对列表进行删除
```


### 对列表进行删除
可以用del命令, 来从列表中删除元素.
例如删除列表中的第六个元素.
```python
del wizard_list[5]
```
### 列表上的算术
把列表进行相加, 可以将这两个列表连起来.
例如下面的代码.
```python
list1 = [1,2,3,4]
list2 = ['i','ate','chocolate','and','i','want','more']
list3 = list1 + list2
print(list1 + list2)
print(list3)
```

可以把列表乘以衣蛾数字
```python
list1 = [1,2]
print(list1*5)
```
> 将会输出[1,2,1,2,1,2,1,2,1,2]

列表的算术中只有+和*.
没有-和/.

不能把列表以外的其他东西加到列表上, 否则会得到一个错误.
```python
list1 + 50
# 上面这种写法是错误的
```

## 元组
元组就像是一个使用括号的列表.
可以使用跟列表一样的索引来获取对应位置上的元素.
元组与列表的主要区别在于元组一旦创建成功就不能再做改动了.
当试图改动元组内的元素时,python会报错.
下面是示例:
```python
fibs = (0,1,2,3,4)
print(fibs[3])
```

```python
# 下面的代码是错误的.
fibs[0] = 4
```

### 使用元组的原因
为什么还要用元组而不用列表呢? 主要是因为有时候对一些你知道永远不会改变的事情还是很有用的. 如果你创建一个由两个元素组成的列表,它里面将一直放着这两个元素.


## 字面
python里面的map不是用来指路的.
字典叫dict, 也叫map,映射. 也就是一堆东西的组合.
字典与列表或元组不同的地方在于字典中的每一个元素都有一个键和一个对应的值.
下面是字典的示例:
```python
favorite_sports = {
	'Ralph Williams' : 'Football',
	'Michael Tippett': 'Basketabll',
	'Edward Elgar' : 'Baseball',
	'Rebeccal Clarke' : 'Netball',
	'Ethel Smyth' : 'Badminton',
	'Frank Brideg' : 'Rugby'
}
print(favorite_sports['Rebeccal Clarke'])
```

要获取对应的值, 就要在字典后面索引相对于的键.

### 删除和替换字典中的值
删除和替换的操作都需要字典中的键
下面的代码分别展示了对字典进行删除和替换的操作.
```python
del favorite_sports['Ethel Smyth']
print(favorite_sports)

favorite_sports['Ralph Williams'] = 'Ice Hockey'
print(favorite_sports)
```

### 错误操作
字典不能进行算术, 因为在python看来, 这样子没有意义, 所以它只能放弃.


## 用海龟画图就必学了, 没啥用

## if
这里的部分很简单, 留下一些示例就行了.
```python
age = 12
if age > 10:
	print(age)

if age == 10:
	print(age)
else:
	print(age)

if age > 10:
	print(age)
elif age == 10:
	print(age)
elif age <= 10:
	print(age)
else:
	print(age)
```

## 逻辑
and表示和
or表示或
not表示非
具体用法和c语言一样
这里不提供示例了

## 字符串与数字不同
可以用函数来将字符串变成数字, 也可以用函数把数字编程字符串.
下面的示例演示了这两个操作.
```python
age = '10'
converted_age = int(age)

bge = 10
other_converted_age = str(bge)
```

上面的示例是用整数来转化的, 如果是小数的话, 上网查查用什么函数来进行转换, 这里书本没有提供.


## 没有值的变量--None
与c语言中null差不多, 不过记得大写
这个None是一个变量, 里面只有一个值, 就是None.
代表的是空.


## 循环
看代码来解读, 不然用文字不好描述.
```python
for x in range(0,5)
```
上面这个代码包括for_in结构, x变量, range函数

for_in结构就是循环结构.
x变量, 就是把in后面的内容循环存放在x变量里面.
range函数是一个迭代器, 他会在每次循环的时候依次返回一个指定范围内的值. 在这里, 依次返回0,1,2,3,4, 不包括5.

可以以下代码得到一个列表.
```python
print(list(range(10,20)))
# 打印出[10,11,12,...,19]
```
list()不是一个函数, 而是一个列表变量.
range()相当于一个系统事先实现的循环, 依次向list()里面存入指定范围的值.
用这种方式就可以创造一段有序的列表.


### in后面
in后面可以存放列表. 会依次for循环列表内的值存入循环变量中.
```python
wizard_list=['spider legs', 'toe of frog', 'snail tongue','bat wing','slug butter','bear burp']
for i in wizard_list:
	print(i)
# 会依次将list内的元素打印出来.
```


### 一段for循环示例
```python
found_coins=20
magic_coins=70
stolen_coins=3
coins = found_coins
for week in range(1,53):
	coins = coins + magic_coins - stolen_coins
	print('week %s = %s' % (week, coins))
```

## while循环
for循环是针对指定长度的循环, 而while循环则用于你事先不知道何时停止的情况.

while循环中的变量需要事先建立,不然python会报错.
while循环条件要为true
```python
while true:
	code
# 这个code会一直被执行.
```


## 使用函数
函数是重用代码的一种方式.
一个函数有三个部分组成: 名字,参数,还有函数体.
下面是一个简单的函数示例:
```python
def testfunc(myname):
	print('hello %s' % myname)

testfunc('Mary')

#可以是多参函数
def testfunc(fname, lname):
	print("hello %s %s" % (fname, lname))
```

函数可以有返回值
下面是一个示例:
```python
def saving(pocket_money, paper_route, spending):
	return pocket_money + paper_route - spending
print(saving(10,10,5))
```
返回的可以是一个表示式的值.
有返回值的函数, 打印出来就是返回值.


## 变量和作用域
1. 在函数体内的变量在函数执行结束后就不能再用了, 因为他只在函数中存在.
2. 在编写程序的世界里, 这被称为"作用域"

作用域的话, 各个程序里面差不多都是通用的原则.不用代码示例了.

## 使用模块
用improt来导入模块
用.来调用这个模块中的函数.
下面的例子就是如何调用time模块中的asctime函数.
```python
import time
print(time.asctime())
#将会输出星期, 日期, 时间, 年份
```

如果需要别人用你的程序输入一个值, 可以使用sys模块, 这个是system的缩写. 其中包含了与python系统自身交互的工具.

里面有一个很有用的函数叫readline, 用来读取来自键盘的一行文本输入, 直到你按回车键为止.(会在后面解释对象是如何工作的.)
下面是示例代码:
```python
import sys
print(sps.stdin.readline())
```

一个用来判断用户年龄的简单代码.
```python
def silly_age_joke():
	print('How old are you?')
	age = int(sys.stdin.readline())
	if age >= 10 and age <=13:
		print('What is 13+12+12+13?')
	else:
		print('Huh?')
```

## 把事物拆分成类
呃, 如果要描述类与对象的话, 书本中作者的解释是十分生动的. 只用文字的话是无法好好描述这种东西的特性的, 以及为什么要怎么做的理由. 如果要理解这些的话, 只能回去看书了. 书中有图, 也有作者的生动的比喻.
这里的话还是只留下一些示例代码吧.

1. 创建一个类
```python
class Inanimate():
	pass
```

2. 让一个类继承另外一个类. 这个时候, 被继承的类是父类.
```python
class Animate(Things):
	pass
```
直接写在括号里就是了.

3. 增加属于类的对象.
直接赋值就可以了.
```python
class Animate(Things):
	pass
a = Animate()
```
后面会涉及到如何给定参数.


## 定义在类中的函数
1. 一个没有与任何类关联的普通函数:
```python
def this_is_a_normal_function():
	print('i am a normal function')
```

2. 两个属于类的函数
```python
class ThisIsMySillyClass:
	def this_is_a_class_function():
		print()
	def this_is_also_a_class_function():
		print()
```

## 用函数来表示类的特征
特征就是一个类家族中的所有成员(还有它的子类)共同的特点.
例如, 所有的哺乳动物都给他们的孩子喂奶, 而且他们也呼吸, 动, 和吃东西. 那么我们可以将喂奶, 呼吸, 动, 吃东西这四个函数添加到哺乳动物这个类里面.
```python
class Animals(Animate):
	def breathe(self):
		pass
	def move(self):
		pass
	def eat_food(self):
		pass
```
这里的self参数会发生什么, 在后面会提及.
不过在类里面定义函数, 第一个参数必须写上self.
将pass放在函数里面, 先将一整个框架构建起来, 是写程序经常做的一种方法,

每个类都可以使用它父类的特征, 这意味着你不需要把一个类写得很复杂. 可以把函数放在这一特征最早出现的父类中. 这样子就可以保持简洁了.
```python
class Mammals(Animals):
	def feed_young_with_milk(self):
		pass

class Giraffes(Mammals):
	def eat_leaves_from_trees(self):
		pass
```


## 为什么使用类和对象
1. 可以通过.来调用类里面的函数. 
2. 对象与对象之间的动作是独立的.
3. 对象是计算机中的, 而不是现实中的, 不会影响到现实(笑)
4. 每次创建对象都是新的, 哪怕是重名的, 也不一定会消失.


## 对象和类的另一些实用功能
- 类和对象是给函数分组的好办法, 他们还帮助我们把程序分成小段来分别思考.
- 分成类的话, 可以给别人分工, 来共同完成这个程序.


## 函数继承
任何在父类中定义的函数在子类中都可以用.

## 从函数里调用其他函数
当我们调用一个对象的函数时, 我们要使用这个对象的变量名, 就像这样:
```python
reginald.move()
```

看示例:
```python
class Giraffes(Mammals):
	def find_food(self):
		self.move()
		print("i've found food!")
		self.eat_food()
```
在这里, move()和eat_food()都是同属于Giraffes这个类下的函数(可能再父类也可能在现在这个类里面), 如果要在函数里面调用函数的话, 就要使用self, 这样子无论在父类还是在子类, 都可以把函数给调用出来.

而不会发生找不到函数的情况.

这在编写程序的时候很常见, 通常, 你会写个做些有意义的事情函数, 然后在另外一个函数内使用他. 在后面的时候, 会涉及到这种复杂的函数.

> 这种东西的话, 没有文档的话, 如果是别人写的话, 一定十分难读吧


## 初始化对象
当我们创建对象时, 我们可以设置一些值以便将来使用, 这些值也叫属性, property.
当我们初始化对象时, 我们是在为将来使用他做准备.

__init__是python类里的一种特殊类型的函数, 并且只能叫这个名字.
这个__init__函数是在对象被创建的同时就设置他的属性的一种方法,python会在我们创建新对象时自动调用这个函数.
例如:
```python
class Giraffes:
	def __init__(self, spots):
		self.giraffe_spots = spots
```
self是第一个参数, spots是一个参数.
可以看做是, 将参数spots的值, 用对象变量giraffe_spots来存储, 方便下次使用.

这个与在类中的函数用self来调用类中的另一个函数一样, 类里的变量也用self来关联.
self是自己的意思.


接着上面的那个例子, 创建两个长颈鹿对象, 并显示他们的斑点数, 就能看见初始化函数起作用了.
```python
ozwald = Giraffes(100)
gertrude = Giraffes(150)

print(ozwald.giraffe_spots)
print(gertrude.giraffe_spots)
```

对象, 也叫实例.


## python的内建函数
python 提供了一大堆编程工具, 包括了很多可以直接使用的函数和模块, 就像一个可靠的锤子或修自行车的扳手一样, 这些内建的工具, 或者说一段段的代码, 会让你写程序十分地轻松.

python的内建函数不需要像模块那样要引用后才能使用, 只要python程序一启动, 他们就可以用了.

## 使用内建函数
这里会学习写python常用的12个内建函数, 会描述他们是做什么的, 以及如何使用他们, 然后会给出示例代码, 介绍他们是如何帮助你写程序的.

### abs函数
- abs函数会返回一个数字的绝对值, 也就是去掉数字的正负号后的值.
- 参数内填数字或者变量.
```python
print(abs(10))

print(abs(-10))
```


### bool函数
bool函数只有一个参数, 并根据这个参数的值返回真或者假.
当对数字使用bool函数时, 0返回假, 其他值都返回真.
这里真是True, 假是False
```python
print(bool(0))
print(bool(1))
print(bool(1123.23))
print(bool(-500))
```

当对其他类型的值使用bool时, 比如字符串, 罪域没有值的字符串, 返回假, 否则返回真.
例如:
```python
print(bool(None))
print(bool('a'))
print(bool(' '))
print(bool('what do you call a pig doing karate? pork chop!'))
```

bool函数对于空的列表,元组,和字典返回False, 否则就返回True
```python
my_silly_list=[]
print(bool(my_silly_list))

my_silly_list=['s','i','l','l','y']
print(bool(my_silly_list))
```

可以用bool函数来判断一个值是否已经被设置.
例如, 如果我们叫人们用我们的程序来输入他的出生年份, 我们的if语句可以用bool来验证输入的值.
```python
year = input('year of birth: ')

if not bool(year.rstrip()):
	print('you need to enter a value for your year of birth')
```
input与上面曾经写过的sys.stdin.readline()的效果是一样的.
rstrip()会把字符串结尾的空白和回车删除.


### dir函数
dir是directory的缩写, 目录的意思.
可以返回关于任何值的相关信息.
基本上他就是按着字母顺序告诉你那个值上面可以使用的函数都有什么.

例如, 要显示对一个列表值可用的函数,可以这样输入:
```python
dir('a','short','list')
```

dir函数基本上可以用于任何东西, 包括字符串,数字,函数,模块,对象,还有类.
但有时候他返回的值可能没有什么用处.
例如对数字1调用dir(), 会显示python自己使用的特殊函数, 例如__abs__, 这并没有什么用...
因为你通常不用关心他们中的大多数, 这些都是给python自己用的.
```python
dir(1)
```

可以通过dir快速找出在一个变量上可以做些什么, 然后再利用help函数来获取相应的帮助.
例如, 对变量调用dir, 会得到一系列str类所提供的函数.
```python
popcorn = 'i love popcorn!'
dir(popcorn)
help(popcorn.upper)
```
对于help返回的信息, 其实很容易看懂.
(...)意味着函数参数内是没有参数的, 而且意味着这是一个内建的函数.
->的意思是这个函数返回值是什么类型的, ->str就是返回一个字符串.
还会有关于这个函数的英文描述.

### eval函数
这个是evaluate,估值的缩写.
把一个字符串作为参数并返回它作为一个python表达式的结果.
例如
```python
eval('print("wow")')

#等于下面这个
print("wow")
```

eval函数只能用于简单的表示式.
```python
eval('10 * 5')
```

拆分成多行的表达式,例如if语句, 一般不能运算.

eval函数常用于把用户输入转换成python表达式.
例如,写一个简单的计算器程序, 它会读取python中的算式, 然后计算出答案.

由于用户的输入被当成字符串读进来, python如果要进行计算的话需要把他转换成数字和运算符. eval函数使得这种转换很简单.
```python
your_calculation = input('Enter a calculation: ')
eval(your_calculation)
```
输入12*12的话, 会直接输出144在最后一行.


### exec函数
这个和eval函数差不多, 但是他可以运行更复杂的程序.
两者之间的不同在于, eval返回一个值, 而exec不返回.
例如:
```python
my_small_program = '''print('ham')
print('sandwich')
'''
exec(my_small_program)
```
当运行上面的代码的时候, 两个print都会被执行.

甚至可以用exec来运行python程序从文件中读入的小程序, 也就是程序中又包含了程序.
比如, 游戏中读取脚本, 这里的脚本也是一个程序.
读取程序之后, 这个程序会对本来的程序产生影响.


### float函数
这个是转换float用的, 浮点数.
浮点数就是10.0,10.1这些带小数点的数字, 或者说实数.
可以用这个函数将字符串转换成浮点数.
```python
float('12') #12.0
float('123.456') #123.456
```

可以用float来把程序中的输入转换成恰当的数字, 尤其是在你需要把某人的输入与其他值做比较的时候这很有用.
```python
your_age = input('enter your age: ')
age = float(your_age)
if age > 13:
	print('you are %s years too old' % (age - 13))
```
虽然这个示例看起来并不是那么有用...


### int函数
int函数会把字符串或者数字转换成整数, 这样会把小数点后面的内容丢掉.
如果要把一个包含有浮点数的字符串转换成整数, 会得到一个错误信息.
但是把一个包含有浮点数的数字转换成整数是可以的.


### len函数
len函数返回一个对象的长度, 对于字符串则返回字符串中的字符个数.
```python
print(len('this is a test string')) #21 包括空格
```
如果使用在列表或元组时, len函数返回列表或元组中的元素的个数
```python
creature_list = ['union','cyclops']
print(len(creature_list)) #2
```

如果用在字典是, len函数会返回字典中元素的个数.
```python
enemies_map = {
	'batman' : 'joker',
	'superman' : 'lex luthor',
	'spiderman' : 'Green Goblin'
}
print(len(enemies_map)) #3
```

在循环中len函数尤其有用, 我们可以用下面的代码来显示列表中元素的索引位置.
```python
fruit = ['apple', 'banane', 'clementine', 'dragon fruit']
length = len(fruit)
for x in range(0, length):
	print('the fruit at index %s is %s' % (x, fruit[x]))
```

### max和min函数
max函数返回列表,元组或字符串中最大的元素.
例如,下面是对数字列表使用max函数.
```python
number = [5,4,10,30,22]
print(max(numbers)) #30
```

由逗号或空格分隔的字符串也有同样的效果:
```python
strings = 's,t,r,i,n,g,S,T,R,I,N,G'
print(max(strings)) #t
```
 因为字母是按照字母表的顺序排列的,并且小写字母比大写字母靠后,所以最大的是t.


不一定非要用列表,元组,或者字符串,可以直接调用max函数,把要比较的元素作为参数写在括号后面.
```python
print(max(10,300,450,50,90))
#450
```

min函数与max函数一样, 只是它返回列表,元组,字符串中的最小元素.


max函数的一个应用, 用于猜数游戏:
看看谁的比较大:
```python
guess_this_number = 61
player_guesses = [12,15,70,45]
if max(player_guesses) > guess_this_number:
	print("boom! you all lose")
else:
	print('you win')
```


### range函数
range函数在之前用了很多次, 主要应用在for循环中.
range函数实际返回了一个叫做迭代器的特殊对象, 他能重复一个动作很多次.
可以把迭代器转换成列表,使用list函数,然后如果你打印对range调用的返回值,你会看到它所包含的数字.
```python
print(list(range(0,5)))
#[0,1,2,3,4]
```

range还有第三个参数叫步长.
下面有两个例子.
```python
count_by_twos = list(range(0,30,2))
print(count_by_twos)
#0,2,4,6,8...28
```

```python
count_down_by_twos = list(range(40,10,-2))
print(count_down_by_twos)
#40,38,36,34,...,12
```
看例子就知道这个步长可以怎么用了.

### sum函数
sum把列表中的元素加在一起并返回这个总和.
```python
my_list_of_number = list(range(0,500,50))
print(my_list_of_number)
#[0,50,100,...,450]
print(sum(my_list_of_number))
#2250
```


## 使用文件
计算机上所有的东西都是以文件的形式保存的.
可以使用python里如何使用内建函数open来打开和操作文件.
因为涉及到了其他文件, 所以示例项目在本目录下的一个文件夹里面.

主要的实现原理就是:
用一个函数来打开文件, 然后把打开后的文件信息存储到一个变量上, 这样子这个变量就是一个拥有文件信息的对象了.
然后就可以调用相关的函数来执行一些操作.
最后还可以调用一些函数来关闭文件, 让这个对象消失.


## 常用的python模块
python的模块就是一些函数,类和变量的组合.
python用模块来把函数和类分组, 使他们更方便使用.
接下来会介绍python自带模块里面最有用的部分, 并进行尝试.

### 使用copy模块来复制
copy模块中包含了制作对象的拷贝的函数.
如果想要创建一个对象, 这个对象是另外一个对象的复制品, 而且这个被复制的对象创建过程及其复杂的时候,就可以用到这个.
```python
import copy

class Animal:
	def __init__(self, species, number_of_legs, color):
		self.species = species
		self.number_of_legs = number_of_legs
		self.color = color
harry = Animal('hippogriff',6,'pink')
harriet = copy.copy(harry)
```
在这里, 如果打印harry.species, harriet.species 结果都是一样的.
在这里, 是创建了一个新的对象, 改变原来的对象并不会影响到新的对象.

```python
harry = Animal('hippogriff',6,'pink')
carrie = Animal('chimera',4,'green polka dots')
billy = Animal('bogill',0,'paisley')
my_animals = [harry,carrie,billy]
more_animals = copy.copy(my_animals)
print(more_animals[0].species) #hippogriff
print(more_animals[1].species) #chimera
```
在这里用copy将一个存有三个对象的列表给复制到了另外一个对象里面,然后more_animals就变成列表了.
里面存放的东西和原来复制的那个列表里的东西都是一模一样的.

python的列表里面什么都可以放, 因为万物皆对象.

但是,看下面
```python
my_animals[0].species='ghoul'
print(my_animals[0].species) #ghoul
print(more_animals[0].species) #ghoul
```
改变了原来列表的值, 竟然会把复制后的列表也改变了
因为这里copy实际上只做了'浅拷贝',他没有真的拷贝我们要拷贝的对象中的对象.
在这里, 他拷贝了主对象list对象, 但是并没有拷贝到list内部的每一个对象. 虽然我们得到了一个新的列表, 但是里面的对象并不是新的, 还是原来的那三个对象.

还有
```python
sally = Animal('sphinx',4,'sand')
my_animals.append(sally)
print(len(my_animals)) #4
print(len(more_animals)) #3
```
虽然添加了一个新的对象在原来的列表里面, 但是因为没有重新进行一次copy, 所以新列表并没有增加这个对象, 所以长度还是3.
如果要弄清楚这是什么回事的话, 就要深入到python的内部了.可能要好好看看这个copy函数是怎么回事.


有另外一个函数deepcopy,会创建被拷贝对象中的所有对象的拷贝.
当我们用这个函数来复制my_animals时,我们会得到一个新列表, 他的内容是所有对象的拷贝.
这样做的结果是, 对于原来的列表Animal对象的改动不会影响到新列表.
```python
more_animals=copy.deepcopy(my_animals)
my_animals[0].species='wyrm'
print(my_animals[0].species) #wyrm
print(more_animals[0].species) #ghoul
```
从上面可以看到, 对原来列表的修改并没有影响到新的列表.


### keyword模块记录了所有的关键字
iskeyword()返回一个字符串是否为python关键字
kwlist变量包含了python关键字的列表.
不过要注意, 新版和旧版的python的关键字有些不同.
下面是一些示例:
```python
import keyword
#会返回布尔值用来判断是不是关键字.
print(keyword.iskeyword('if')) #True
print(keyword.iskeyword('if')) #False
print(keyword.kwlist) #会把一个包含了所有关键字的列表打印出来
```


### 用random模块获得随机数
randint()可以在一个数字范围内随机挑选一个数字, 比如在1-100之间.
下面是一个例子:
```python
import random
print(random.randint(1,100))
print(random.randint(100,1000))
print(random.randint(300,20000))
```

可以用来写一个简单又无聊的猜数字游戏
```python
import random
num = random.randint(1,100)
while (True):
	print('Guess a number between 1 and 100')
	guess = input()
	i = int(guess)
	if i == num:
		print('you guessed right')
		break
	elif i < num:
		print('Try higher')
	elif i > num:
		print('Try lower')
```

用choice从列表中随机选取一个元素
例如, 你想要让python帮你选一个甜品
```python
import random
desserts = ['ice cream', 'pancakes', 'brownies', 'cookies', 'candy']
print(random.choice(desserts))
```


用shuffle函数来给列表洗牌
可以将列表里面的元素打乱.
```python
import random
desserts = ['ice cream', 'pancakes', 'brownies', 'cookies', 'candy']
random.shuffle(desserts)
print(desserts)
```
使用函数之后, 再次打印就可以看到列表里面的元素排列顺序变了, 可以用来做卡牌游戏的洗牌.


### 用sys模块来控制shell程序
在这个模块里面有一些系统函数,用来控制python shell程序自身.
接下来会介绍exit(), stdin和stdout对象, 还有一个version变量.

#### 用exit函数来推出shell程序
```python
import sys
sys.exit()
```
上面这个代码会有提示对话问你是否有退出, 选择yes, shell程序就会关闭.
...好像并没有出现这个提示...


### 从stdin对象读取
stdin对象是standard input'标准输入'的简写, 会提示用户输入信息, 读取到shell程序中并在程序中使用.
他就像input函数那样.
```python
import sys
v = sys.stdin.readline()
print(v)
```
按下回车之后就会停止输入了.


input和readline的区别之一就是readline函数可以用一个参数来指定读取多少个字符.
```python
v = sys.stdin.readline(13)
print(v)
```
上面这个代码只会读取用户输入的13个字符, 包括空格, 超过13个字符之后的东西不会再读取进去.


#### 用stdout对象来写入
与stdin不同, stdout对象是standard output`标准输出`的简写, 可以用来向控制台写消息, 而不是从中读入.
在某些方面, 与print函数相同, 但是stdout是一个文件对象, 因此他可以使用文件的函数, 例如.write等等.
```python
import sys
sys.stdout.write("what does a fish asy when it swims into a wall")
```
当write函数结束之后, 会返回所写入字符串的个数.
同时, 也会将写入的字符串显示在控制台上.

这个函数有点难驾驭, 他会在输出东西之后接着输出返回值...
看看日后怎么使用他.


#### python是什么版本的
变量version表示python的版本, 可以把python的版本信息放在'关于'的窗口中.例如:
```python
import sys
print(sys.version)
```


### 用time模块来得到时间
time模块中包含了表示时间的函数
```python
import time
print(time.time())
```
但是返回的结果可能不太符合想象...
因为对time()的调用会返回1970年1月1日00:00:00Am以来的秒数...
虽然很奇怪, 但是这种罕见的表现形式还是有点用的
例如, 想要计算你程序的某一部分要运行多久, 可以在开始和结束时记录时间, 然后比较两个值.

下面是一个程序, 算一下打印从0到999的所有的数字需要多少时间
```python
import time

def lots_of_numbers(max):
	t1 = time.time()
	for x in range(0,max):
		print(x)
	t2 = time.time()
	print('it took %s seconds' % (t2-t1))


lots_of_numbers(1000)
```

#### 用asctime函数来转换日期
这个函数是以日期的元组为参数, 将它转换为更可读的形式.
如果不用任何参数调用, 这个函数会以可读的形式返回当前的日期和时间.
```python
import time
print(time.asctime())
```
会返回星期 月份 日期 时间 年份

要带参数调用asctime, 首先要创建一个包含日期和时间数据的元组.
例如, 这里我们把元组赋值给变量t:
```python
t = (2007,5,27,10,30,48,6,0,0)
```
这一系列数值分别是,年,月,日,时,分,秒,星期几,一年中的第几天,是否为夏令时时间.
在这里:
	星期一用0表示
	一年中的第几天用0来表示占位符
	夏令时时间用0代表不是,用1代表是
```python
print(time.asctime(t))
#Sun Feb 23 10:30:48 2020
```

#### 用localtime函数来得到日期和时间
与asctime不同, 函数localtime会把当前的日期和时间作为一个对象返回, 其中的值大体与asctime的参数顺序一样.
如果你打印这个对象, 你就会看到类的名字, 还有其中的每一个值.

这些值被标记为
	tm_year(年)
	tm_mon(月)
	tm_mday(日)
	tm_hour(时)
```python
import time
print(time.localtime())
#time.struct_time(tm_year=2020, tm_mon=2, tm_mday=23, tm_hour=22, tm_min=18, tm_sec=39, tm_wday=0, tm_yday=73, tm_isdst=0)
```
要打印当前的年和月,可以用他们的索引位置, 就像对asctime所用的元组一样.
年在第一个位置,而月在第二个位置
所以可以
```python
t = time.localtime()
year = t[0]
month = t[1]
print(year)
print(month)
```

#### 用sleep来休息一会
```python
import time
for x in range(1,61):
	print(x)
	time.sleep(1)
```
上面这个代码会每隔一秒钟打印一次数字
sleep就是来让程序慢下来的.


## 用tkinter画高级图形
前面还有一个部分是用来介绍海龟作图的, 但是现代作图可不是用海龟画的.
所以这里学习一个新的模块.

### 创建一个可以点的按钮
```python
from tkinter import *
tk = TK()
btn = Button(tk, text="click me")
btn.pack()
```
第一行的from,是直接将模块里面的东西导入到这个文件里面.
这说明在接下来的使用过程中, 不用在用tkinter.xxx的形式来调用这个模块里面的函数了.
但是, 如果函数发生重名的话, 就不太好用了.
而且这种方法还看不到模块名.

上面的这个代码创建了一个包含TK类对象的变量tk, tk对象创建了一个基本的窗口, 我可以在上面增加其他东西.
这个是tkinter模块提供的最主要的类.
.pack()是让那个按钮显示在那个窗口上.

接下来是一个按下按钮显示文字的例子:
```python
from tkinter import *

def hello():
	print('hello')
tk = Tk()
btn = Button(tk, text="click me", command=hello)
btn.pack()
```
当点击按钮的时候, 会在shell里面打印hello.
上面的代码使用了一个具名参数
### 使用具名参数
这个玩意和普通的参数一样, 只是它不是按照函数所提供的参数的顺序来决定哪一个参数获取哪一个值.
我们可以明确地定义值的名字,所以可以写成任何顺序.

有的时候,函数有很多参数, 我们不是总要所有的参数都赋值,具名参数可以让我们只为我们想给他赋值的参数赋值.
下面两个代码是普通参数和具名参数的区别:
```python
def person(width,height):
	print("width is $s, height is #s" % (width, height))
# 1
person(4,3)
# 2
person(height=3,width=4)
```

### 创建一个画图用的画布
如果要画图的话, 需要一个canvas(画布)对象,也就是Canvas类的对象.
当我们创建一个画布的时候,我们传入画布的宽度和高度(以像素为单位).
```python
from tkinter import *
tk = Tk()
canvas = Canvas(tk,width=500,height=500)
canvas.pack()
```
pack函数让画布显示在窗口中正确的位置上,如果没有调用这个函数, 就不会正常地显示任何东西.

### 让窗口保持固定
教程上的代码直接运行是看不到窗口的,还需要调用一个函数
```python
import tkinter
windows = Tk()
...
windows.mainloop() #需要这个函数才会让窗口保持.
```

### 画线
需要用到像素坐标.
在一个tkinter画布上,坐标决定了从左到右和从上到下的距离.

例如,500宽500高的窗口,起点坐标是在左上角(0,0),终点坐标在右下角(500,500)
我们可以用cerate_line函数来指定这些坐标.
```python
from tkinter import *
tk = Tk()
canvas = Canvas(tk, width=500, height=500)
canvas.pack()
canvas.create_line(0,0,500,500) #1
```
返回了一个1, 这是一个标志, 以后再来了解他.

接下来看看canvas对象上都有哪些可用的函数,可以用他们来进行更有趣的绘画.

### 画盒子
在下面这段代码中, 我们用tkinter创建一个400宽400高的画布,然后在窗口的左上角画一个正方形.
```python
from tkinter import *
tk = Tk()
canvas = Canvas(tk,width=400,height=400)
canvas.pack()
canvas.create_rectangle(10,10,50,50)
```
对于rectangle,前面两个数字分别是左上角定点的坐标(10,10),(这里的坐标系与godot差不多,y坐标向下)
最后两个数字是正方形右下角的坐标(50,50)

也可以用这个函数来画一个长方形
这个长方形的左上角顶点坐标是(10,10),
右下角顶点坐标是(300,50)
```python
from tkinter import *
tk = Tk()
canvas = Canvas(tk,width=400,height=400)
canvas.pack()
canvas.create_rectangle(10,10,300,50)
tk.mainloop()
```

这里影响图形的就是开始坐标和结束坐标

### 画许多矩形
可以用random随机模块, 然后写一个函数来用随机数作为矩形左上角和右下角的坐标
```python
from tkinter import *
import random
tk = Tk()
canvas = Canvas(tk,width=400,height=400)
canvas.pack()
def random_rectangle(width,height):
	x1 = random.randrange(width)
	y1 = random.randrange(height)
	x2 = x1 + random.randrange(width)
	y2 = y1 + random.randrange(height)
	canvas.create_rectangle(x1,y1,x2,y2)
for x in range(0,100):
	random_rectangle(400,400)
tk.mainloop()
```

### 设置颜色
还可以为矩形设置颜色.
只需要将create_rectangle(x1,y1,x2,y2,fill = fill_color)
里面添加那个fill参数就可以了.
fill_color是一个颜色值,
可以是系统中设定好的颜色值,例如'green' 'yellow'...
但是颜色显示的是什么取决于系统.

还可以用十六进制的颜色表示法.
例如:`#FFFFFF`

在python里面也是可以将十六进制转换成十进制的, 使用%x来输出.
更多的细节可以上网查查, 还可以控制输出的位数.


tkinter还提供里一个取色器来给我们使用.
```python
from tkinter import *
colorchooser.askcolor()
```
这个代码会显示一个界面, 当选择一个颜色然后按下确定之后, shell就会返回一个元组, 元组里面还有一个元组和一个十六进制数, 那个元组表示的是红绿蓝的量, 十六进制表示的就是这个颜色.

可以把这个元组当做一个变量来使用, 只需要用到索引.
```python
c = colorchooser.askcolor()
random_rectangle(400,400,c[1])
```


## 结尾
虽然书上关于如何用tkinter模块进行画图的部分还没有完全学完, 但是用这个东西画那些图形的意义不是很大.所以就到此为止了.
接下来的部分, 就是去系统的去学习tkinter这个模块到底能做什么.
然后就是把这个笔记上面的部分就行第二次归纳总结.
接着就是用去系统学习python自带的一些函数和模块.
然后去网络上看看一些进阶视频.
同时去学习python版本下的数据结构与算法
去了解软件工程的思想和方法,同时去学习一下游戏开发模式这些.
等这些东西都完成了之后, 估计也过了好几个月了, 这个时候就可以去开发自己的第一个demo
















