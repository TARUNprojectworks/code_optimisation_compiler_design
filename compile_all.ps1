# Compile all C files at 5 optimization levels
$GCC = "C:\msys64\mingw64\bin\gcc.exe"
$SRC = "c:\Users\TARUN\Desktop\Code Optimization\src"
$EXE = "c:\Users\TARUN\Desktop\Code Optimization\exe"

$files = @("cf", "dce", "cse", "cp", "licm", "ivsr", "inline", "loop", "simd", "alias")
$opts = @("O0", "O1", "O2", "O3", "Os")

foreach ($f in $files) {
    foreach ($o in $opts) {
        $flag = "-$o"
        $out = "$EXE\${f}_${o}.exe"
        $src = "$SRC\$f.c"
        Write-Host "Compiling $f with $flag -> $out"
        & $GCC $flag -o $out $src 2>&1
        if ($LASTEXITCODE -ne 0) {
            Write-Host "  ERROR compiling $f with $flag" -ForegroundColor Red
        }
    }
}

Write-Host "`nDone! All executables are in: $EXE"
Write-Host "Run timing with: Measure-Command { .\exe\cf_O0.exe }"
