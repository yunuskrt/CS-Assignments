# Use an official Node.js runtime as a parent image
FROM node:18

# Set the working directory
WORKDIR /usr/src/app

# Copy package.json and package-lock.json
COPY package*.json ./

# Install dependencies
RUN npm install

# Copy the rest of the application code
COPY . .

# Expose the port the app runs on
ENV PORT 8000
ENV HOST 0.0.0.0
EXPOSE 8000


# Define the command to run the application
CMD ["node", "index.js"]
