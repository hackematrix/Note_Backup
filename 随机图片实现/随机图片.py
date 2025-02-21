import requests
import matplotlib.pyplot as plt
from PIL import Image
from io import BytesIO

def fetch_random_image():
    try:
        # 发送 GET 请求
        response = requests.get('https://api.miaomc.cn/image/get', allow_redirects=True)
        
        # 检查请求是否成功
        if response.status_code != 200:
            raise Exception(f"请求失败，状态码: {response.status_code}")
        
        # 获取重定向后的图片 URL
        image_url = response.url
        print(f"随机图片的 URL: {image_url}")
        
        # 下载图片
        image_response = requests.get(image_url)
        if image_response.status_code != 200:
            raise Exception("无法下载图片")
        
        # 使用 PIL 打开图片
        image = Image.open(BytesIO(image_response.content))
        
        # 使用 matplotlib 显示图片
        plt.imshow(image)
        plt.axis('off')  # 不显示坐标轴
        plt.show()
        
        # 如果需要保存图片到本地
        save_image = input("是否保存图片到本地？(y/n): ").strip().lower()
        if save_image == 'y':
            with open('random_image.jpg', 'wb') as file:
                file.write(image_response.content)
            print("图片已保存为 random_image.jpg")
        
    except Exception as e:
        print(f"发生错误: {e}")

if __name__ == "__main__":
    fetch_random_image()
