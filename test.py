MORSE_CODE_DICT = {
    'A': '.-',
    'B': '-...',
    'C': '-.-.',
    'D': '-..',
    'E': '.',
    'F': '..-.',
    'G': '--.',
    'H': '....',
    'I': '..',
    'J': '.---',
    'K': '-.-',
    'L': '.-..',
    'M': '--',
    'N': '-.',
    'O': '---',
    'P': '.--.',
    'Q': '--.-',
    'R': '.-.',
    'S': '...',
    'T': '-',
    'U': '..-',
    'V': '...-',
    'W': '.--',
    'X': '-..-',
    'Y': '-.--',
    'Z': '--..',
    '1': '.----',
    '2': '..---',
    '3': '...--',
    '4': '....-',
    '5': '.....',
    '6': '-....',
    '7': '--...',
    '8': '---..',
    '9': '----.',
    '0': '-----',
    '.': '.-.-.-',
    ',': '--..--',
    '?': '..--..',
    '/': '-..-.',
    '-': '-....-',
    '(': '-.-.--',
    ')': '-.--.-',
}

def decode_morse_code(morse_code):
    morse_code_dict_reverse = {v: k for k, v in MORSE_CODE_DICT.items()}
    result = ''
    for code in morse_code.split(' '):
        if code in morse_code_dict_reverse:
            result += morse_code_dict_reverse[code]
        else:
            result += '?'
    return result

morse_code = '... --- ...'
decoded_text = decode_morse_code(morse_code)
print(decoded_text)
