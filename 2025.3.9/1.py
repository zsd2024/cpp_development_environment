import requests
from bs4 import BeautifulSoup
import re
import html
import json
import html2text


def unescape_html(s):
    s = s.replace(r"\t", "\t")
    s = s.replace(r"\r", "\r")
    s = s.replace(r"\n", "\n")
    s = s.replace(r"\\", "\\")
    s = s.replace(r"\'", "'")
    s = s.replace(r"\"", '"')
    return s


def fetch_problem_details(pid):
    # 目标 URL
    url = f"http://ybt.ssoier.cn:8088/problem_show.php?pid={pid}"

    # 发送 GET 请求
    response = requests.get(url)

    # 检查请求是否成功
    if response.status_code == 200:
        # 解析 HTML 内容
        soup = BeautifulSoup(response.content, "html.parser")

        print(f"Problem {pid}...")

        # 获取题目名称
        problem_name = soup.find("center").find("h3").text
        print(f"题目名称: {problem_name}")

        # 获取题目描述
        problem_description_script = (
            soup.find("h3", string="【题目描述】").find_next_sibling("script").string
        )
        problem_description = re.search(
            r'pshow\("(.+?)"\);', problem_description_script
        ).group(1)
        problem_description = unescape_html(problem_description)
        problem_description = html2text.html2text(problem_description)
        problem_description = unescape_html(problem_description)
        # print(problem_description)

        # 获取输入描述
        input_description_script = (
            soup.find("h3", string="【输入】").find_next_sibling("script").string
        )
        input_description = re.search(
            r'pshow\("(.+?)"\);', input_description_script
        ).group(1)
        input_description = html2text.html2text(input_description)
        # print (input_description)

        # 获取输出描述
        output_description_script = (
            soup.find("h3", string="【输出】").find_next_sibling("script").string
        )
        output_description = re.search(
            r'pshow\("(.+?)"\);', output_description_script
        ).group(1)
        output_description = html2text.html2text(output_description)
        # print (output_description)

        # 获取输入样例
        input_sample = (
            soup.find("h3", string="【输入样例】").find_next_sibling("font").pre.string
        )
        input_sample = html.unescape(input_sample)
        input_sample = html2text.html2text(input_sample)

        # 获取输出样例
        output_sample = (
            soup.find("h3", string="【输出样例】").find_next_sibling("font").pre.string
        )
        output_sample = html.unescape(output_sample)
        output_sample = html2text.html2text(output_sample)

        # 创建字典
        problem_details = {
            "题目ID": pid,
            "题目名称": problem_name,
            "题目描述": html.unescape(problem_description),
            "输入描述": html.unescape(input_description),
            "输出描述": html.unescape(output_description),
            "输入样例": html.unescape(input_sample),
            "输出样例": html.unescape(output_sample),
        }

        return problem_details
    else:
        print("无法访问该页面，状态码:", response.status_code)
        return None


print(unescape_html(r"aaa\nbbb"))

# Collect all problem details
all_problems = []

# Example usage
for i in range(1422, 1670):
    print(f"Fetching problem {i}...")
    try:
        problem_details = fetch_problem_details(i)
        if problem_details:
            all_problems.append(problem_details)
    except Exception as e:
        print(f"An error occurred while fetching problem {i}: {e}")
        all_problems.append(
            {"题目ID": i, "error": f"An error occurred while fetching problem {i}: {e}"}
        )

# Output all problems to a single JSON file
with open("all_problems.json", "w", encoding="utf-8") as file:
    json.dump(all_problems, file, ensure_ascii=False, indent=4)
