pipeline {
    agent any
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
            echo "build successfully"
        }
        failure
        {
            echo " build failed"
        }
    }
    
}
