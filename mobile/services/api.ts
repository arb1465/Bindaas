import axios from "axios";

const BASE_URL = "http://10.159.70.251:5000";

export const api = axios.create({
  baseURL: BASE_URL,
});