pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'javac PipeLine.java' // Compile your Java file
            }
        }
        stage('Run') {
            steps {
                sh 'java PipeLine' // Run the compiled Java class
            }
        }
    }
}
