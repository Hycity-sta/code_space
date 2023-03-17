# 对1-6code的解读

## 1_code的解读
```python
# 下面这些模块会在屏幕上显示一个小窗口

import sys
from PyQt5.QtWidgets import QApplication, QWidget
# 导入最基础的模块


if __name__ == '__main__':
    app = QApplication(sys.argv)# 所有的PyQt5应用都必须创建一个QApplication对象
	# sys.argv是一个来自命令行的参数列表,因为python脚本可以在shell中运行,这是我们用来控制我们应用启动的一种方法


	# 创建了一个对象,这个对象的类没有父类,会使用默认的构造方法
	# 没有父类的widget组件将被作为窗口使用
    w = QWidget()
    w.resize(350,350)#调整了widget组件的大小,宽和高
    w.move(300,300)#调整了这个组件出现在屏幕的位置,分别是x和y坐标
    w.setWindowTitle('my first windows')#设置了窗口的标题
    w.show()#显示这个窗口
	
	# 最后应用进入主循环,事件处理开始执行.
	# 如果我们调用exit(),或者将主widget组件销毁,主循环将推出
	# 下面这个方法将确保一个不留垃圾的退出,系统环境会被通知应用是怎样被结束的.
    sys.exit(app.exec_())# 里面的exec_有一个下划线,因为exec是py的保留字,所以不能直接用.
	# 这一行的意思就是说当程序退出的时候就调用app对象里面的一个exec_方法,用来退出
```

## 2_code的解读
```python
# 这部分的代码将会给窗口添加一个图标
import sys
from PyQt5.QtWidgets import QApplication, QWidget #导入最基础的模块
from PyQt5.QtGui import QIcon #导入图标
 
 
class Example(QWidget):
     
    def __init__(self):
        super().__init__()#调用父类的构造方法
         
        self.initUI()

    def initUI(self):
		#下面的这三个方法都是父类的方法
        self.setGeometry(300, 300, 300, 220)
		# 上面这个,前两个参数定位了窗口的xy位置,后两个定义了窗口了宽度和长度

        self.setWindowTitle('Icon')#指定窗口的名称
        self.setWindowIcon(QIcon('web.png'))#为窗口添加图标, 里面填的是路径,如果没有路径的话就会在工作目录下寻找图片      
        self.show()#显示窗口

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
```

## 3_code的解读
```python
import sys
from PyQt5.QtWidgets import QWidget, QPushButton, QApplication
from PyQt5.QtCore import QCoreApplication

class Example(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):              
        qbtn = QPushButton('Quit', self)
        qbtn.clicked.connect(QCoreApplication.instance().quit)
        qbtn.resize(qbtn.sizeHint())
        qbtn.move(50, 50)      

        self.setGeometry(300, 300, 250, 150)
        self.setWindowTitle('Quit button')   
        self.show()

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
```
