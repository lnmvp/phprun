# LNMVP - 最小 PHP 解释器实现 🚀

## 项目简介 💡

LNMVP 是一个从零开始构建的轻量级 LNMP（Linux, Nginx, MySQL, PHP）生态系统，目标是通过 C 语言实现 Web 服务器、PHP 解释器、数据库和前端框架的最简版本。我们希望通过构建最小化系统，帮助开发者理解底层实现原理，逐步构建更复杂的 Web 应用。 

## 功能概述 ⚙️

`phprun` 是一个用 C 语言编写的最小 PHP 解释器，目标是解析并执行最基础的 PHP 代码。

- ✅ 能执行最基本的 PHP 代码
- ✅ 处理变量、数学运算、字符串操作
- ✅ 能嵌入 nginxrun 解析 PHP 文件

## 如何编译和运行 🖥️

1. 进入项目目录并编译代码：

   ```bash
   cd phprun
   make
   ```

2. 运行 phprun：

   ```bash
   ./phprun
   ```

## 贡献 🤝

如果你有任何问题、想法或改进建议，欢迎提交 Issues 或 Pull Requests！你的贡献对我们来说非常重要 🚀。

## 联系方式 📬

- 公众号：不止编程OS
- B站：[不止编程OS](https://space.bilibili.com/1095200610)

## 许可协议 📑

本项目采用 MIT 许可证，详情请查看 [LICENSE](LICENSE) 文件。