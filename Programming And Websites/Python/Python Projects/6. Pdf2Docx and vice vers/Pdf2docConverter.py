
# PDF to DOCX Conversion
# from pdf2docx import Converter
#
# old_pdf = "Sahil Jangid.pdf"
# new_doc = "Sahil Jangid.docx"
# obj = Converter(old_pdf)
# obj.convert(new_doc)
# obj.close()

# DOCX to PDF Conversion
from docx2pdf import convert

convert("Sahil Jangid.docx", "SJ.pdf")


