# Git 快速入门：

## 1. 先安装 Git

Windows 推荐安装：

https://git-scm.com/download/win

安装时大部分选项保持默认即可。安装完成后，重新打开 VS Code。

检查是否安装成功：

```bash
git --version
```

如果能看到版本号，例如 `git version 2.x.x`，说明成功。

## 2. 第一次设置名字和邮箱

只需要设置一次。

```bash
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"
```

例子：

```bash
git config --global user.name "student"
git config --global user.email "student@example.com"
```

## 3. 把当前 C++ 文件夹变成 Git 仓库

在 `D:\VScode\c++` 这个文件夹里执行：

```bash
git init
```

执行后，这个文件夹就有“版本记录能力”了。

## 4. 查看当前状态

```bash
git status
```

常见意思：

- 红色文件：Git 发现了，但还没准备保存。
- 绿色文件：已经放进暂存区，准备提交。
- clean：当前没有未保存的修改。

## 5. 第一次保存代码

建议先只保存源码和笔记，不保存 `.exe`、`.obj`、`.pdb`、`.ilk` 这些编译产物。

```bash
git add *.cpp *.md
git commit -m "first cpp learning notes"
```

含义：

- `git add`：选择要保存的文件。
- `git commit`：正式保存一个版本。
- `-m` 后面是这次保存的说明。

## 6. 以后每天怎么用

写代码前或写完后先看状态：

```bash
git status
```

查看自己改了哪里：

```bash
git diff
```

保存这次练习：

```bash
git add *.cpp *.md
git commit -m "practice prefix sum"
```

查看历史：

```bash
git log --oneline
```

## 7. 建议的提交说明

算法学习可以这样写：

```bash
git commit -m "practice array basics"
git commit -m "practice sort problems"
git commit -m "add prefix sum template"
git commit -m "practice binary search"
git commit -m "practice bfs grid"
```

## 8. 不建议保存的文件

这些通常是编译生成的文件，不需要存进 Git：

```text
*.exe
*.obj
*.pdb
*.ilk
```

以后可以建一个 `.gitignore` 文件来自动忽略它们。

## 9. 最小必会命令

```bash
git status
git add 文件名
git commit -m "说明"
git log --oneline
git diff
```

先把这五个用熟。

