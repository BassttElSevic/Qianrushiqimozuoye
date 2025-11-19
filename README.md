chuanchuankou
=================

这是一个 STM32（STM32F1）工程，使用 CMake / STM32CubeMX 生成的工程结构。

目的
----
将整个项目放到 Git 仓库以便版本管理、备份与协作。仓库中已添加 `.gitignore` 来避免提交构建产物与 IDE 配置文件。

快速开始（Windows cmd.exe）
--------------------------
1. 打开命令提示符（cmd.exe），切换到项目根目录：

    cd /d C:\eng\chuanchuankou

2. 初始化本地仓库并提交所有源代码：

    git init
    git add .
    git commit -m "Initial commit: import existing project"

3. 在 GitHub/GitLab/Bitbucket 上创建一个新仓库（方法一：网页）。
   - 登录 GitHub，点击 New repository，填写仓库名（例如 chuanchuankou），创建仓库。

   方法二：使用 GitHub CLI（可选，需先安装 gh）：

    gh repo create your-username/chuanchuankou --public --source=. --remote=origin --push

4. 或者手动添加远程并推送（把 URL 换成你自己的仓库地址）：

    git remote add origin https://github.com/<your-username>/chuanchuankou.git
    git branch -M main
    git push -u origin main

注意事项
--------
- .gitignore 已包含常见的构建目录（例如 cmake-build-debug-stm-32/）和编译产物（*.elf、*.bin、*.map 等）。检查并根据需要调整。
- 如果仓库中含有大二进制文件（例如大图、固件二进制），建议使用 Git LFS（https://git-lfs.github.com/）：

    git lfs install
    git lfs track "*.bin"
    git add .gitattributes

  然后像平常一样 add/commit/push。注意：GitHub 对单文件 100MB 有限制，LFS 也有配额限制。

常见问题
--------
- 已有 .git 仓库但想重新开始：先备份，然后删除 .git 目录：

    rmdir /s /q .git

- 想忽略更多临时文件：编辑 `.gitignore`，然后运行：

    git rm -r --cached .
    git add .
    git commit -m "Update .gitignore"

如果你愿意，我可以：
- 1) 现在帮你在本地执行 `git init`/`git add`/`git commit`（我可以运行命令，但无法为你创建远程仓库或推送到需要凭据的远程）；
- 2) 或者给你一条逐步的检查清单，让你在自己的机器上执行并验证每一步。

你想让我现在替你在本地运行初始化并提交（无需远程）吗？或者你希望我直接尝试把代码推到你已有的远程（这需要你提供远程 URL 或临时授权令牌）？

