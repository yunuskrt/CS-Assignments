require('dotenv').config()

const express = require('express')
const connectDB = require('./src/configs/db')
const cors = require('cors')
const userRoute = require('./src/routes/userRoute')
const articleRoute = require('./src/routes/articleRoute')
const commentRoute = require('./src/routes/commentRoute')
const app = express()
connectDB()
app.use(cors())
app.use(express.json())
app.use(express.urlencoded({ extended: true }))
app.use('/api/user', userRoute)
app.use('/api/article', articleRoute)
app.use('/api/comment', commentRoute)
app.use('/', (req, res) => {
	res.send(`${req.method} Route ${req.path} not found !`)
})
const port = process.env.PORT || 8000;

app.listen(port, () => {
	console.log(`server run on port ${port} ✅`)
})
