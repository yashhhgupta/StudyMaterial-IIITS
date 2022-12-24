const mongoose = require("mongoose")
const Schema = mongoose.Schema

const userSchema = new Schema({
    username: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true
    },
    email: {
        type: String,
        required: true
    },
    rguit: {
        type: Boolean,
        default: false
    },
    comguit: {
        type: Boolean,
        default: false
    },
    rbb: {
        type: Boolean,
        default: false
    },
    combb: {
        type: Boolean,
        default: false
    },
    rsud: {
        type: Boolean,
        default: false
    },
    comsud: {
        type: Boolean,
        default: false
    },
    rchess: {
        type: Boolean,
        default: false
    },
    comchess: {
        type: Boolean,
        default: false
    },
}) 

const User = mongoose.model("User", userSchema)
module.exports = User