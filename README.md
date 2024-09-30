# Video Processing Application

## תיאור
אפליקציית עיבוד וידאו המבוססת על OpenCV. האפליקציה מאפשרת חיתוך, שינוי גודל, סיבוב, הוספת טקסט ופילטרים על קובצי וידאו. 

## דרישות
- OpenCV
- GStreamer (שימוש לא הושלם עדיין)
- CMake
- Git

## התקנה
1. **התקנת OpenCV**:
   - יש להוריד ולהתקין את OpenCV למערכת שלך.
   - יש להגדיר את הנתיב ל-OpenCV במערכת (PKG_CONFIG_PATH).

2. **התקנת GStreamer**:
   - יש להוריד ולהתקין את GStreamer. (שימוש לא הושלם עדיין בפרויקט).

3. **התקנת CMake**:
   - יש להוריד ולהתקין את CMake.


## איך להריץ
1. **בניית הפרויקט**:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release

   ./Release/VideoProcessingApp.exe "<נתיב לקובץ הווידאו>"

