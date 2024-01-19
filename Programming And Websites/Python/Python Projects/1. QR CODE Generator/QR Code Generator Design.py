
import qrcode

qr = qrcode.QRCode(version=1,
                   error_correction=qrcode.constants.ERROR_CORRECT_H,
                   box_size=10, border=2)

qr.add_data("https://sahiljangid.github.io/Portfolio/")

qr.make(fit=True)

img = qr.make_image(fill_color = "white", back_color = "black")

img.save("Portfolio_Sahil.png")


