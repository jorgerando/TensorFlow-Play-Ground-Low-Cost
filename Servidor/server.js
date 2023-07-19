const express = require('express');
const app = express();

app.use(express.static('.'));

const port = 3000;
app.listen(port, () => {
  console.log(`Servidor en ejecución en http://localhost:${port}`);
});
