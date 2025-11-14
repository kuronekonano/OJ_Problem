import asyncio
import tkinter as tk
import threading
import time


# ---------- 协程任务 ----------
async def io_task(task_id):
    print(f"Task {task_id} start", threading.current_thread().ident)
    await asyncio.sleep(3)  # 模拟耗时 I/O
    print(f"Task {task_id} done")

# ---------- GUI 点击事件 ----------
def start_task():
    global task_counter
    task_counter += 1
    asyncio.create_task(io_task(task_counter))
    print("main thread:", threading.current_thread().ident)
    label_var.set(f"Running {task_counter} tasks")

# ---------- 主窗口 ----------
root = tk.Tk()
root.title("Tkinter + Asyncio Demo")
root.geometry("300x150")

task_counter = 0
label_var = tk.StringVar(value="No tasks running")

label = tk.Label(root, textvariable=label_var)
label.pack(pady=20)

button = tk.Button(root, text="Start IO Task", command=start_task)
button.pack()

# ---------- 将 Tkinter 主循环与 asyncio 集成 ----------
async def main_loop():
    while True:
        try:
            root.update()  # 处理 GUI 事件
        except tk.TclError:
            break  # 窗口关闭时退出循环
        await asyncio.sleep(0.01)  # 给协程调度留出时间

# ---------- 启动事件循环 ----------
print("current python3 thread:",threading.current_thread().ident)
asyncio.run(main_loop())
