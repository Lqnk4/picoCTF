from pwn import *

context.log_level = "critical"
context.binary = ELF('format-string-3')

p = process("./format-string-3")

def exec_fmt(payload):
    p = process("./format-string-3")
    log.info("payload = %s" % repr(payload))
    p.sendline(payload)
    return p.recvall()

s = p.recvall()

