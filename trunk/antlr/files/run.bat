antlr -o ..\source Dbc.g4 && javac ..\source\*.java && cd ..\source && grun Dbc database -gui ..\files\faw.dbc && cd ..\files
