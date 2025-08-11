# 生成测试数据（Linux/macOS）
dd if=/dev/urandom of=data.bin bs=24 count=10

# Windows 可以使用 PowerShell
$bytes = 0..23 | % { Get-Random -Minimum 0 -Maximum 255 }
[IO.File]::WriteAllBytes("data.bin", [byte[]]$bytes)
