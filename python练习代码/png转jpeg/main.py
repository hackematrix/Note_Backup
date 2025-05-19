from PIL import Image

try:
    image=Image.open("D:\\piture\\images.png")
except Exception as e:
    print(f"无法打开图片:{e}")


image=image.convert('RGB')
image.save("D:\\leetcode_code\\demo_js\\arch.jpeg")
