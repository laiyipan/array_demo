#Git操作指南
##1.使用Github
1）注册个人github账号。
(www.github.com)
2）创建仓库。
点击New
![创建仓库](pics\2019-12-02_135831.png "创建仓库")

填入必要信息
![创建仓库](pics\2019-12-02_135955.png "创建仓库")

创建仓库成功
![创建仓库成功](pics\2019-12-02_140255.png "创建仓库成功")

##2.使用Git
###安装Git客户端

![安装Git客户端](pics/2019-12-02_133445.png "安装Git客户端")
下载对应的版本，并安装。
###使用GitBash
任意目录右键，选择Git Bash Here
输入git，查看git相关命令
![安装Git客户端](pics/2019-12-02_133641.png "安装Git客户端")

####克隆仓库
```git
git clone https://github.com/laiyipan/array_demo.git
```
![克隆仓库](pics\2019-12-02_140527.png "克隆仓库")
![克隆仓库](pics\2019-12-02_140846.png "克隆仓库")
![克隆仓库](pics\2019-12-02_141434.png "克隆仓库")


####初始化仓库 ：Git init
```git
git init
```
####配置仓库：
```git
git config --global user.name "ASxx"
git config --global user.email "123456789@qq.com" 
```
在 vs 中每次更新代码都会要输入账号密码，可以配置一下让 GIT 记住密码账号（非必须）：
```git
git config --global credential.helper store
```


##3.在VSCode中使用Git
前提：已安装VSCode
###打开工程文件夹
![增加文件](pics\2019-12-02_142047.png "增加文件")
![stage文件](pics\2019-12-02_142139.png "stage文件")
![commit文件](pics\2019-12-02_142228.png "commit文件")
![准备推送](pics\2019-12-02_142305.png "准备推送")
![推送](pics\2019-12-02_142317.png "推送")
![推送失败](pics\2019-12-02_142358.png "推送失败")
原因在于当前的github 账号是ClimbSong，不是laiyipan，如下图：
```git
git config user.name
```
```git
git config user.email
```
```git
$ git config --list
```
![Git信息查看](pics\2019-12-03_092710.png "Git信息")
切换当前github账号：

```git
git config --global user.name "laiyipan"
git config --global user.email "345075153@qq.com" 
```
![Github账号切换](pics\2019-12-03_095311.png "Github账号切换")
在vscode中，继续push，仍然denied。
需删除已经有的github管理凭证：
![管理凭证](pics\2019-12-03_100457.png "管理凭证")
在vscode中，继续push，弹出：
![输入github账号](pics\2019-12-03_100641.png "输入github账号")
输入对应的账号及密码，Push成功。
新的管理凭证产生
![新的管理凭证](pics\2019-12-03_101610.png "新的管理凭证")

根目录增加新的文件夹：
Array/array.c
Basic/hello.c
note.txt
随后，commit，push。

###使用GitLens查看日志
前提：安装了GitLens插件。
点击①，进入GitLens.点击②，把光标移动到第5行。
>GitLens是VScode插件，比VScode自带的Source Control功能要更强大。


![查看历史](pics\2019-12-03_103101.png "查看历史")
区域③显示当前文件array.c的历史日志
区域④显示当前文件当前行的历史日志。

如下图，点击①Copy Commit ID to Clipboard，到②Terminal,输入如下：
```git
git log --name-only -n1 08c5175f27e29cfdc2dbcb4d7637e2db2fd24871
```
![查看](pics\2019-12-03_105713.png "查看")
展现了本次Commit的信息

再次修改array.c,增加注释，如下图
![查看](pics\2019-12-03_111027.png "查看")
commit后，push，注意观察左侧展示的History

###使用 Git History
![历史](pics\2019-12-03_111954.png "历史")

##4.其他功能