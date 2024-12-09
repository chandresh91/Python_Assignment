pipeline {
    agent any
    environment
    {    VERSION_NAME="1.0.0"
    }
    
    stages {
        stage('Build') {
            steps {
                bat 'javac PipeLine.java' // Compile your Java file
            }
        }
        stage('Run') {
            steps {
                bat 'java PipeLine' // Run the compiled Java class
            }
        }
    }
    post
    {
        always
        {
            echo "build success"
        }
        success
        {
            echo "${VERSION_NAME} build successfully"
        }
        failure
        {
            echo " build failed"
        }
    }
    
}
