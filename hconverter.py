from PIL import Image

def convert_image_to_header(image_path, output_path, var_name):
    img = Image.open(image_path).convert('RGB')
    width, height = img.size
    pixels = list(img.getdata())

    with open(output_path, 'w') as f:
        f.write(f'#define {var_name}_WIDTH {width}\n')
        f.write(f'#define {var_name}_HEIGHT {height}\n')
        f.write(f'const uint16_t {var_name}[] PROGMEM = {{\n')

        for i, (r, g, b) in enumerate(pixels):
            # Convert RGB888 to RGB565 (little endian)
            rgb565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
            # Swap bytes for little endian
            rgb565_swapped = ((rgb565 & 0xFF) << 8) | (rgb565 >> 8)
            f.write(f'0x{rgb565_swapped:04X}, ')
            if (i + 1) % 12 == 0:
                f.write('\n')

        f.write('\n};\n')

# Convert 'Pixelmare.bmp' to 'Pixelmare_image.h'
convert_image_to_header("Pixelmare.bmp", "Pixelmare_image.h", "PixelmareImage")