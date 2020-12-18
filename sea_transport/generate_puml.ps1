$pumlFile = "output.puml"
if (Test-Path $pumlFile) {
    Write-Host Found old file. Resolution: delete
    Remove-Item $pumlFile
}

$cmd = "hpp2plantuml -i *.h"
# hpp2plantuml -i *.h -i entities\*.h -o output.puml
foreach ($dir in $(Get-ChildItem -Path $Source -Directory -Recurse)) {
    $cmd += " -i '$($dir.FullName)\*.h'"
}

$cmd += " -o $pumlFile"
Invoke-Expression $cmd

Exit(0)