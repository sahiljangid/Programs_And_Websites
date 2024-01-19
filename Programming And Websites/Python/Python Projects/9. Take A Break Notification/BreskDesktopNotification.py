from plyer import notification
import time

while True:
    notification.notify(
        title = "+++ Take Rest +++",
        message = "Rest is vital for better mental health, increased concentration and memory.",
        app_icon = "rest.ico",
        timeout = 10
    )
    time.sleep(20)
