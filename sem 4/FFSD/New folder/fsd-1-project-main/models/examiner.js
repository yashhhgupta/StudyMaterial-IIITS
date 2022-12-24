const mongoose = require("mongoose")
const Schema = mongoose.Schema

const examinerSchema = new Schema({


}, {timestamps: true})

const Examiner = mongoose.model("Examiner", examinerSchema)
module.exports = Examiner