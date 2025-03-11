import requests
from bs4 import BeautifulSoup
import re
import html
import time

def fetch_problem_details(pid):
    # 目标 URL
    url = f"http://ybt.ssoier.cn:8088/problem_show.php?pid={pid}"

    # 发送 GET 请求
    response = requests.get(url)

    # 检查请求是否成功
    if response.status_code == 200:
        # 解析 HTML 内容
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # 获取题目描述
        problem_description_script = soup.find('h3', string="【题目描述】").find_next_sibling('script').string
        problem_description = re.search(r'pshow\("(.+?)"\);', problem_description_script).group(1)
        problem_description = html.unescape(problem_description)
        
        # 获取输入描述
        input_description_script = soup.find('h3', string="【输入】").find_next_sibling('script').string
        input_description = re.search(r'pshow\("(.+?)"\);', input_description_script).group(1)
        input_description = html.unescape(input_description)
        
        # 获取输出描述
        output_description_script = soup.find('h3', string="【输出】").find_next_sibling('script').string
        output_description = re.search(r'pshow\("(.+?)"\);', output_description_script).group(1)
        output_description = html.unescape(output_description)
        
        # 获取输入样例
        input_sample = soup.find('h3', string="【输入样例】").find_next_sibling('font').pre.string
        input_sample = html.unescape(input_sample)
        
        # 获取输出样例
        output_sample = soup.find('h3', string="【输出样例】").find_next_sibling('font').pre.string
        output_sample = html.unescape(output_sample)
        
        # 输出到文件
        with open(f'problem_{pid}.txt', 'w', encoding='utf-8') as file:
            file.write(f"题目描述:\n{problem_description}\n\n")
            file.write(f"输入描述:\n{input_description}\n\n")
            file.write(f"输出描述:\n{output_description}\n\n")
            file.write(f"输入样例:\n{input_sample}\n\n")
            file.write(f"输出样例:\n{output_sample}\n")
    else:
        print("无法访问该页面，状态码:", response.status_code)

# Example usage
for i in range(1422, 1670):
    print(f"Fetching problem {i}...")
    try:
        fetch_problem_details(i)
    except Exception as e:
        print(f"An error occurred while fetching problem {i}: {e}")
        i -= 1
        time.sleep(5)