#!/bin/bash

# 遍历当前目录中的所有文件
for file in *; do
    # 检查是否为文件
    if [ -f "$file" ] && [ "$file" != "$(basename "$0")" ]; then
        # 获取文件名（不包括扩展名）
        filename="${file%.*}"
        
        # 创建同名子文件夹（如果不存在）
        mkdir -p "$filename"
        
        if [ $? -eq 0 ]; then
            echo "已创建 $filename/ 文件夹"
        else
            echo "创建 $filename/ 文件夹失败"
        fi

        # 复制文件到子文件夹
        cp "$file" "$filename/"
        
        if [ $? -eq 0 ]; then
            echo "已将 $file 复制到 $filename/ 文件夹中"
        else
            echo "复制 $file 到 $filename/ 文件夹失败"
        fi
    fi
done