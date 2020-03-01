# coding=UTF-8
"""
@Author: David
@Date: 2020-02-22 22:52:26
@Description: 删除文件夹下所有后缀为exe，o和out的文件，并将无后缀名的文件(linux)删除
"""
import os  # 系统库
import re  # 正则库


def remove_files(path, pattern):
    """递归删除文件夹下所有与pattern匹配的文件

    Args:
        path (string): 文件路径
        pattern (re.compile()): 正则表达式
    """
    lsdir = os.listdir(path)  # 列出path下所有文件及文件夹
    # path下所有文件夹
    dirs = [i for i in lsdir if os.path.isdir(os.path.join(path, i))]
    if dirs:
        for i in dirs:
            if i != ".git":
                remove_files(os.path.join(path, i), pattern)
    # path下所有文件
    files = [i for i in lsdir if os.path.isfile(os.path.join(path, i))]
    for f in files:
        # 如果文件与pattern匹配，则删除
        if pattern.match(f):
            os.remove(os.path.join(path, f))


if __name__ == "__main__":
    path = os.getcwd()  # 当前文件所在路径
    # 正则表达式^[^.]$表示无后缀文件，(.*)表示出了换行符的任意个数所有字符
    # [.]表示.符号，(exe|o|out)表示后缀为exe或o或out
    pattern = re.compile(r"^[^.]*$|(.*)[.](exe|o|out)")
    remove_files(path, pattern)
