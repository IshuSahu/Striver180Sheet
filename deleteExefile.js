const fs = require("fs");
const path = require("path");

const deleteExeFiles = (dir) => {
  fs.readdir(dir, (err, files) => {
    if (err) {
      console.error("Error reading directory:", err);
      return;
    }

    files.forEach((file) => {
      const filePath = path.join(dir, file);

      fs.stat(filePath, (err, stats) => {
        if (err) {
          console.error("Error checking stats for file:", err);
          return;
        }

        if (stats.isDirectory()) {
          deleteExeFiles(filePath);
        } else if (path.extname(file) === ".exe") {
          fs.unlink(filePath, (err) => {
            if (err) {
              console.error(`Error deleting file ${file}:`, err);
            } else {
              console.log(`Deleted ${file}`);
            }
          });
        }
      });
    });
  });
};

const currentDirectory = __dirname;
deleteExeFiles(currentDirectory);
