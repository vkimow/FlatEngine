cd ..

if exist project (
    del /f /s /q project
) else (
    mkdir project
)

cd project
call cmake ..
PAUSE

